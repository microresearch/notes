  // this would be where we generate adventure texts
  // based on RTC and moon.c

  // we would have a set of invocations in FLASH that would be re-jumbled into 512 bytes and output here!


/*
 * VirtualFAT.c
 * (c) 2015 flabbergast
 *  Implements a virtual FAT12 filesystem.
 *
 *  Most of the code comes from a LUFA library Demo (license below).
 */

/*
             LUFA Library
     Copyright (C) Dean Camera, 2014.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
*/

/*
  Copyright 2014  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaims all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/** \file
 *
 *  Virtualized FAT12 filesystem implementation, to perform self-programming
 *  in response to read and write requests to the virtual filesystem by the
 *  host PC.
 */

#define  INCLUDE_FROM_VIRTUAL_FAT_C
#include "VirtualFAT.h"
#include "../moon.h"

static const uint8_t readme_contents[] PROGMEM = README_CONTENTS;

/** FAT filesystem boot sector block, must be the first sector on the physical
 *  disk so that the host can identify the presence of a FAT filesystem. This
 *  block is truncated; normally a large bootstrap section is located near the
 *  end of the block for booting purposes however as this is not meant to be a
 *  bootable disk it is omitted for space reasons.
 *
 *  \note When returning the boot block to the host, the magic signature 0xAA55
 *        must be added to the very end of the block to identify it as a boot
 *        block.
 */
static const FATBootBlock_t BootBlock =
  {
    .Bootstrap               = {0xEB, 0x3C, 0x90},
    .Description             = "mkdosfs",
    .SectorSize              = VIRTUALFAT_SECTOR_SIZE_BYTES,
    .SectorsPerCluster       = SECTOR_PER_CLUSTER,
    .ReservedSectors         = 1,
    .FATCopies               = 2,
    .RootDirectoryEntries    = (VIRTUALFAT_SECTOR_SIZE_BYTES / sizeof(FATDirectoryEntry_t)),
    .TotalSectors16          = VIRTUALFAT_LUN_MEDIA_BLOCKS,
    .MediaDescriptor         = 0xF8,
    .SectorsPerFAT           = 1,
    .SectorsPerTrack         = (VIRTUALFAT_LUN_MEDIA_BLOCKS % 64),
    .Heads                   = (VIRTUALFAT_LUN_MEDIA_BLOCKS / 64),
    .HiddenSectors           = 0,
    .TotalSectors32          = 0,
    .PhysicalDriveNum        = 0,
    .ExtendedBootRecordSig   = 0x29,
    .VolumeSerialNumber      = 0x12345678,
    .VolumeLabel             = "xxxxx      ", //12 chars
    .FilesystemIdentifier    = "FAT12   ",
  };

/** FAT 8.3 style directory entry, for the virtual FLASH contents file. */
static FATDirectoryEntry_t FirmwareFileEntries[] =
  {
    /* Root volume label entry; disk label is contained in the Filename and
     * Extension fields (concatenated) with a special attribute flag - other
     * fields are ignored. Should be the same as the label in the boot block.
     */
    [DISK_FILE_ENTRY_VolumeID] =
    {
      .MSDOS_Directory =
        {
          .Name            = "xxxxx      ", //12
          .Attributes      = FAT_FLAG_VOLUME_NAME,
          .Reserved        = {0},
          .CreationTime    = 0,
          .CreationDate    = 0,
          .StartingCluster = 0,
          .Reserved2       = 0,
        }
    },

    /* VFAT Long File Name entry for the virtual firmware file; required to
     * prevent corruption from systems that are unable to detect the device
     * as being a legacy MSDOS style FAT12 volume. */
    [DISK_FILE_ENTRY_README_LFN] =
    {
      .VFAT_LongFileName =
        {
          .Ordinal         = 1 | FAT_ORDINAL_LAST_ENTRY,
          .Attribute       = FAT_FLAG_LONG_FILE_NAME,
          .Reserved1       = 0,
          .Reserved2       = 0,

          .Checksum        = FAT_CHECKSUM('R','E','A','D','M','E',' ',' ','T','X','T'),

          .Unicode1        = 'R',
          .Unicode2        = 'E',
          .Unicode3        = 'A',
          .Unicode4        = 'D',
          .Unicode5        = 'M',
          .Unicode6        = 'E',
          .Unicode7        = '.',
          .Unicode8        = 'T',
          .Unicode9        = 'X',
          .Unicode10       = 'T',
          .Unicode11       = 0,
          .Unicode12       = 0,
          .Unicode13       = 0,
        }
    },

    /* MSDOS file entry for the virtual Firmware image. */
    [DISK_FILE_ENTRY_README_MSDOS] =
    {
      .MSDOS_File =
        {
          .Filename        = "README  ",
          .Extension       = "TXT",
          .Attributes      = 0,
          .Reserved        = {0},
          .CreationTime    = FAT_TIME(1, 1, 0),
          .CreationDate    = FAT_DATE(14, 2, 1989),
          .StartingCluster = 2,
          .FileSizeBytes   = README_FILE_SIZE_BYTES,
        }
    },

  };

/** Starting cluster of the virtual README.TXT file on disk, tracked so that the
 *  offset from the start of the data sector can be determined. On Windows
 *  systems files are usually replaced using the original file's disk clusters,
 *  while Linux appears to overwrite with an offset which must be compensated for.
 */
static const uint16_t* READMEFileStartCluster  = &FirmwareFileEntries[DISK_FILE_ENTRY_README_MSDOS].MSDOS_File.StartingCluster;

/** Updates a FAT12 cluster entry in the FAT file table with the specified next
 *  chain index. If the cluster is the last in the file chain, the magic value
 *  \c 0xFFF should be used.
 *
 *  \note FAT data cluster indexes are offset by 2, so that cluster 2 is the
 *        first file data cluster on the disk. See the FAT specification.
 *
 *  \param[out]  FATTable    Pointer to the FAT12 allocation table
 *  \param[in]   Index       Index of the cluster entry to update
 *  \param[in]   ChainEntry  Next cluster index in the file chain
 */
static void UpdateFAT12ClusterEntry(uint8_t* const FATTable,
                                    const uint16_t Index,
                                    const uint16_t ChainEntry)
{
  /* Calculate the starting offset of the cluster entry in the FAT12 table */
  uint8_t FATOffset   = (Index + (Index >> 1));
  bool    UpperNibble = ((Index & 1) != 0);

  /* Check if the start of the entry is at an upper nibble of the byte, fill
   * out FAT12 entry as required */
  if (UpperNibble)
  {
    FATTable[FATOffset]     = (FATTable[FATOffset] & 0x0F) | ((ChainEntry & 0x0F) << 4);
    FATTable[FATOffset + 1] = (ChainEntry >> 4);
  }
  else
  {
    FATTable[FATOffset]     = ChainEntry;
    FATTable[FATOffset + 1] = (FATTable[FATOffset] & 0xF0) | (ChainEntry >> 8);
  }
}

/** Updates a FAT12 cluster chain in the FAT file table with a linear chain of
 *  the specified length.
 *
 *  \note FAT data cluster indexes are offset by 2, so that cluster 2 is the
 *        first file data cluster on the disk. See the FAT specification.
 *
 *  \param[out]  FATTable     Pointer to the FAT12 allocation table
 *  \param[in]   Index        Index of the start of the cluster chain to update
 *  \param[in]   ChainLength  Length of the chain to write, in clusters
 */
static void UpdateFAT12ClusterChain(uint8_t* const FATTable,
                                    const uint16_t Index,
                                    const uint8_t ChainLength)
{
  for (uint8_t i = 0; i < ChainLength; i++)
  {
    uint16_t CurrentCluster = Index + i;
    uint16_t NextCluster    = CurrentCluster + 1;

    /* Mark last cluster as end of file */
    if (i == (ChainLength - 1))
      NextCluster = 0xFFF;

    UpdateFAT12ClusterEntry(FATTable, CurrentCluster, NextCluster);
  }
}

/** Reads or writes a block of data from/to the physical device FLASH using a
 *  block buffer stored in RAM, if the requested block is within the virtual
 *  firmware file's sector ranges in the emulated FAT file system.
 *
 *  \param[in]      BlockNumber  Physical disk block to read from/write to
 *  \param[in,out]  BlockBuffer  Pointer to the start of the block buffer in RAM
 *  \param[in]      Read         If \c true, the requested block is read, if
 *                               \c false, the requested block is written
 */
static void ReadWriteREADMEFileBlock(const uint16_t BlockNumber,
                                     uint8_t* BlockBuffer,
                                     const bool Read)
{
  uint16_t FileStartBlock = DISK_BLOCK_DataStartBlock + (*READMEFileStartCluster - 2) * SECTOR_PER_CLUSTER;
  uint16_t FileEndBlock   = FileStartBlock + (FILE_SECTORS(README_FILE_SIZE_BYTES) - 1);

  /* Range check the write request - abort if requested block is not within the
   * virtual firmware file sector range */
  if (!((BlockNumber >= FileStartBlock) && (BlockNumber <= FileEndBlock)))
    return;

  #if (FLASHEND > 0xFFFF)
  uint_farptr_t FlashAddress = (uint_farptr_t)readme_contents + (uint_farptr_t)(BlockNumber - FileStartBlock) * VIRTUALFAT_SECTOR_SIZE_BYTES;
  #else
  uintptr_t FlashAddress = (uintptr_t)readme_contents + (uintptr_t)(BlockNumber - FileStartBlock) * VIRTUALFAT_SECTOR_SIZE_BYTES;
  #endif

  // this would be where we generate adventure texts
  // based on RTC and moon.c

  // we would have a set of invocations in FLASH that would be re-jumbled into 512 bytes and output here!
  
  double ecliptic = moon2(2021, 9, 7, 23+5/60., 12.41285, 52.51854);
  
  if (Read)
  {
    
    // Read out the mapped block of data from the device's FLASH 
        for (uint16_t i = 0; i < VIRTUALFAT_SECTOR_SIZE_BYTES; i++)
    {
      /*  #if (FLASHEND > 0xFFFF)
        BlockBuffer[i] = pgm_read_byte_far(FlashAddress++);
      #else
        BlockBuffer[i] = pgm_read_byte(FlashAddress++);
      #endif
      */
      BlockBuffer[i]="i";
    }
  }
  else
  {
    // Do not do anything. We don't want any action on write (yet). 
  }
}

/** Writes a block of data to the virtual FAT filesystem, from the USB Mass
 *  Storage interface.
 *
 *  \param[in]  BlockNumber  Index of the block to write.
 */
void VirtualFAT_WriteBlock(const uint16_t BlockNumber)
{
  uint8_t BlockBuffer[VIRTUALFAT_SECTOR_SIZE_BYTES];

  /* Buffer the entire block to be written from the host */
  Endpoint_Read_Stream_LE(BlockBuffer, sizeof(BlockBuffer), NULL);
  Endpoint_ClearOUT();

  switch (BlockNumber)
  {
    case DISK_BLOCK_BootBlock:
    case DISK_BLOCK_FATBlock1:
    case DISK_BLOCK_FATBlock2:
      /* Ignore writes to the boot and FAT blocks */

      break;

    case DISK_BLOCK_RootFilesBlock:
      /* Copy over the updated directory entries */
      memcpy(FirmwareFileEntries, BlockBuffer, sizeof(FirmwareFileEntries));

      break;

    default:
      ReadWriteREADMEFileBlock(BlockNumber, BlockBuffer, false);

      break;
  }
}

/** Reads a block of data from the virtual FAT filesystem, and sends it to the
 *  host via the USB Mass Storage interface.
 *
 *  \param[in]  BlockNumber  Index of the block to read.
 */
void VirtualFAT_ReadBlock(const uint16_t BlockNumber)
{
  uint8_t BlockBuffer[VIRTUALFAT_SECTOR_SIZE_BYTES];
  memset(BlockBuffer, 0x00, sizeof(BlockBuffer));

  switch (BlockNumber)
  {
    case DISK_BLOCK_BootBlock:
      memcpy(BlockBuffer, &BootBlock, sizeof(FATBootBlock_t));

      /* Add the magic signature to the end of the block */
      BlockBuffer[VIRTUALFAT_SECTOR_SIZE_BYTES - 2] = 0x55;
      BlockBuffer[VIRTUALFAT_SECTOR_SIZE_BYTES - 1] = 0xAA;

      break;

    case DISK_BLOCK_FATBlock1:
    case DISK_BLOCK_FATBlock2:
      /* Cluster 0: Media type/Reserved */
      UpdateFAT12ClusterEntry(BlockBuffer, 0, 0xF00 | BootBlock.MediaDescriptor);

      /* Cluster 1: Reserved */
      UpdateFAT12ClusterEntry(BlockBuffer, 1, 0xFFF);

      /* Cluster 2 onwards: Cluster chain of README.TXT */
      UpdateFAT12ClusterChain(BlockBuffer, *READMEFileStartCluster, FILE_CLUSTERS(README_FILE_SIZE_BYTES));

      break;

    case DISK_BLOCK_RootFilesBlock:
      memcpy(BlockBuffer, FirmwareFileEntries, sizeof(FirmwareFileEntries));

      break;

    default:
      ReadWriteREADMEFileBlock(BlockNumber, BlockBuffer, true);

      break;
  }

  /* Write the entire read block Buffer to the host */
  Endpoint_Write_Stream_LE(BlockBuffer, sizeof(BlockBuffer), NULL);
  Endpoint_ClearIN();
}
