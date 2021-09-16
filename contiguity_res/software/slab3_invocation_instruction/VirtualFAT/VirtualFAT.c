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
#include "../RTC.h"
#include <stdlib.h>

const char str0[] PROGMEM = "I Call Upon You";
const char str1[] PROGMEM = "Assist The Great God";
const char str2[] PROGMEM = "Inhabit Chaos";
const char str3[] PROGMEM = "Inhabit Erebos";
const char str4[] PROGMEM = "Inhabit The Abyss";
const char str5[] PROGMEM = "Inhabit The Depth";
const char str6[] PROGMEM = "Inhabit Earth";
const char str7[] PROGMEM = "Dwell In The Recesses Of Heaven";
const char str8[] PROGMEM = "Lurk In The Nooks And Crannies Of Houses";
const char str9[] PROGMEM = "Shrouded In Dark Clouds";
const char str10[] PROGMEM = "Watch Things Not To Be Seen";
const char str11[] PROGMEM = "Guard Secrets";
const char str12[] PROGMEM = "Lead Those In The Underworld";
const char str13[] PROGMEM = "Administrate The Infinite";
const char str14[] PROGMEM = "Wield Power Over Earth";
const char str15[] PROGMEM = "Shake The Earth";
const char str16[] PROGMEM = "Lay The Foundation";
const char str17[] PROGMEM = "Serve In The Chasm";
const char str18[] PROGMEM = "Turn The Spindle";
const char str19[] PROGMEM = "Freeze Snow And Rain";
const char str20[] PROGMEM = "Cause Summer Heat";
const char str21[] PROGMEM = "Bring Compulsion";
const char str22[] PROGMEM = "Send Flames Of Fire";
const char str23[] PROGMEM = "Bring Snow And Dew";
const char str24[] PROGMEM = "Disturb The Deep";
const char str25[] PROGMEM = "Tread On The Calm Sea";
const char str26[] PROGMEM = "Guard Tartaros";
const char str27[] PROGMEM = "Mislead Fate";
const char str28[] PROGMEM = "Live Simply";
const char str29[] PROGMEM = "Join Together Death";
const char str30[] PROGMEM = "Reveal Angels";
const char str31[] PROGMEM = "Punish Mortals";
const char str32[] PROGMEM = "Revealer The Sunless";
const char str33[] PROGMEM = "Rule Daimons";
const char str34[] PROGMEM = "Transverse Air";
const char str35[] PROGMEM = "I Leak Upon You";
const char str36[] PROGMEM = "Remember The White Target";
const char str37[] PROGMEM = "Be A Powerful User";
const char str38[] PROGMEM = "Heat The Conditions Of Heaven";
const char str39[] PROGMEM = "Lurk In The Results And Cells Of Data";
const char str40[] PROGMEM = "Shroud Yourself From Dark Traces";
const char str41[] PROGMEM = "Gain Information Regarding Characteristics Not Yet To Be Seen";
const char str42[] PROGMEM = "Powder The Various Animals In The Subduction";
const char str43[] PROGMEM = "Change The Infinite";
const char str44[] PROGMEM = "Wield Acquisitions Of The Earth";
const char str45[] PROGMEM = "Observe Birds";
const char str46[] PROGMEM = "Surround Accurate Rain";
const char str47[] PROGMEM = "Leak Byte'S Temperature";
const char str48[] PROGMEM = "Build Structures Of Preferred Data";
const char str49[] PROGMEM = "Bring  Attackers";
const char str50[] PROGMEM = "Null Bits Of Blood";
const char str51[] PROGMEM = "Bring The Same And The Memories";
const char str52[] PROGMEM = "Drive In The Rye";
const char str53[] PROGMEM = "Influence Information";
const char str54[] PROGMEM = "Heat The Results";
const char str55[] PROGMEM = "Mislead The  Manuals";
const char str56[] PROGMEM = "Join Together In Transcience";
const char str57[] PROGMEM = "Walk The Fags";
const char str58[] PROGMEM = "Leak Adversely";
const char str59[] PROGMEM = "Iron-Hearted";
const char str60[] PROGMEM = "Guard Data-Links";
const char str61[] PROGMEM = "Pipe Heads";
const char str62[] PROGMEM = "Black";
const char str63[] PROGMEM = "Decay The Flies";
const char str64[] PROGMEM = "Gladden The Stress";
const char str65[] PROGMEM = "Possess Symptoms";
const char str66[] PROGMEM = "Sex Transistors";
const char str67[] PROGMEM = "Guard Masses";
const char str68[] PROGMEM = "Beckon Fate";
const char str69[] PROGMEM = "Abject All";
const char str70[] PROGMEM = "Time Simply";
const char str71[] PROGMEM = "Extract Sunless Threads Into Dark Stacks";
const char str72[] PROGMEM = "Watch The Things Also To Be Always Seen";
const char str73[] PROGMEM = "Build Technologies Of Those Who Are Always On About The Bandwidth";
const char str74[] PROGMEM = "Leak Infection";
const char str75[] PROGMEM = "Turn The Moduli";
const char str76[] PROGMEM = "Cause Questionable Heat";
const char str77[] PROGMEM = "Bring Of Compulsion";
const char str78[] PROGMEM = "Send Implementations Of Facts";
const char str79[] PROGMEM = "Bring Rain At Setup Time To Servers";
const char str80[] PROGMEM = "Reveal Minutes";
const char str81[] PROGMEM = "Punish Drips";
const char str82[] PROGMEM = "Pin Data";
const char str83[] PROGMEM = "Rule Channels";
const char str84[] PROGMEM = "Radiate Passwords";
const char str85[] PROGMEM = "Condense Chaos";
const char str86[] PROGMEM = "Lurk In The Results And Cells Of Data";
const char str87[] PROGMEM = "Shroud From Dark Traces";
const char str88[] PROGMEM = "Assist The Static God";
const char str89[] PROGMEM = "Compute Things Not Allowed To Be Seen";
const char str90[] PROGMEM = "Measure Spores Of Mucus";
const char str91[] PROGMEM = "Punish Ratings";
const char str92[] PROGMEM = "Signal The Sunless";
const char str93[] PROGMEM = "Grieve In The Hamlet";
const char str94[] PROGMEM = "Disturb The Cloacal";
const char str95[] PROGMEM = "Tread On The Calm Model";
const char str96[] PROGMEM = "Erode Hags For Those In The Underworld";
const char str97[] PROGMEM = "Wield Order Over Earth";
const char str98[] PROGMEM = "Fighter The Rebis";
const char str99[] PROGMEM = "Inferr In Stable Holes";
const char str100[] PROGMEM = "Donate Bits In Earth";
const char str101[] PROGMEM = "Cause Arbitration Heat";
const char str102[] PROGMEM = "Signals Dark Seconds";
const char str103[] PROGMEM = "Send Researchers To The Fire";
const char str104[] PROGMEM = "Be Mighty In Mushrooms";
const char str105[] PROGMEM = "Expose Stable Dew In Sclerotial Clouds";
const char str106[] PROGMEM = "Dream Of Sunless Leakage";
const char str107[] PROGMEM = "Inhabit Mucus";
const char str108[] PROGMEM = "Dance In The Units Within Heaven";
const char str109[] PROGMEM = "Lurk Aside From The Users And Pipes Of Sessions";
const char str110[] PROGMEM = "Adopt Dark Spores";
const char str111[] PROGMEM = "Code Simply";
const char str112[] PROGMEM = "Lie With A Last Session In Our Muscle And Marrow";
const char str113[] PROGMEM = "In Dancers And Pipes, In The Brain Itself";
const char str114[] PROGMEM = "Outgas To The Very Crows.";
const char str115[] PROGMEM = "I Leak Upon You";
const char str116[] PROGMEM = "Memories Of The White Target";
const char str117[] PROGMEM = "Drive In The Rye";
const char str118[] PROGMEM = "Powder Acoustics";
const char str119[] PROGMEM = "Walk The Cliffs";
const char str120[] PROGMEM = "Dissipated Plastic,";
const char str121[] PROGMEM = "Exploit Heating Results";
const char str122[] PROGMEM = "Engender Misleading Manuals";
const char str123[] PROGMEM = "Hear All Inhuman Signs";
const char str124[] PROGMEM = "Gladdening The Sensors";
const char str125[] PROGMEM = "Be Always On About The Bandwidth";
const char str126[] PROGMEM = "Bring Compulsion";
const char str127[] PROGMEM = "Implement Of Facts";
const char str128[] PROGMEM = "Bring Rain At Setup Time To Servers";
const char str129[] PROGMEM = "Form Memorials Within The Calm Sea";
const char str130[] PROGMEM = "Be Mighty In Replica";
const char str131[] PROGMEM = "Hold Memories Of The Heart";
const char str132[] PROGMEM = "Reveal The Minutes";
const char str133[] PROGMEM = "Thin Acoustic Glass";
const char str134[] PROGMEM = "Take Minutes Of Daimons";
const char str135[] PROGMEM = "Assist The Static God";
const char str136[] PROGMEM = "Compute";
const char str137[] PROGMEM = "Lie On The Margins Of Secret Flies";
const char str138[] PROGMEM = "Cycle Two-Phase Daimons";
const char str139[] PROGMEM = "Form Tassels Of Fate";
const char str140[] PROGMEM = "Lay Foundations";
const char str141[] PROGMEM = "Cohere In A Conglomerate,";
const char str142[] PROGMEM = "Shudder At Memorials";
const char str143[] PROGMEM = "Turn The Lawns And Gullies Of Compulsion";
const char str144[] PROGMEM = "Produce Flames Of Fire";
const char str145[] PROGMEM = "Bring Vegetable And Topology";
const char str146[] PROGMEM = "Disturbe The Deep";
const char str147[] PROGMEM = "Dance In Applications";
const char str148[] PROGMEM = "Post-Date Inhabitants Of Chaos And Pipe The Crusts,";
const char str149[] PROGMEM = "Powerdown Basym Hump Sabao'Th Iao' Burn-In Mortroum Earth Beard";
const char str150[] PROGMEM = "Temperatures Reveal All Of The Sedimented Matter And Mind";
const char str151[] PROGMEM = "Hold The Whole Cinnabar";
const char str152[] PROGMEM = "Hold The Most Subordinate";
const char str153[] PROGMEM = "Hold The Most Ignored,";
const char str154[] PROGMEM = "Hold The One Who Eats Wasps";
const char str155[] PROGMEM = "Sink In Nakedness";
const char str156[] PROGMEM = "Bring The Light Eternal Of The Sun'S Rays";
const char str157[] PROGMEM = "Eternal Ruler Of The Poles";
const char str158[] PROGMEM = "Route Within Eternal Boundaries";
const char str159[] PROGMEM = "Sing With Eternal Eyes";
const char str160[] PROGMEM = "Take Rye For Hair";
const char str161[] PROGMEM = "Form Pollen Of Compulsion";
const char str162[] PROGMEM = "Point The Suction And The Direction Without The Aid Of The Server Or The Stage";
const char str163[] PROGMEM = "Foam Beautifully";
const char str164[] PROGMEM = "Extend The \"Who Am I\"";
const char str165[] PROGMEM = "Dance To \"Those Who Die Not\"";
const char str166[] PROGMEM = "Devour \"Those Who Die Untimely\"";
const char str167[] PROGMEM = "Feed On Filth";
const char str168[] PROGMEM = "Entrain Protocol,";
const char str169[] PROGMEM = "Stir The Purple To Subduction";
const char str170[] PROGMEM = "Shake Under Darkness";
const char str171[] PROGMEM = "Produce Ground";
const char str172[] PROGMEM = "Walk In Fauna";
const char str173[] PROGMEM = "Cause A Forest Of Exchanges";
const char str174[] PROGMEM = "Form Corruption";
const char str175[] PROGMEM = "Hand Off The Centre";
const char str176[] PROGMEM = "Picture A Silicate Time";
const char str177[] PROGMEM = "Smite Circles Of Light";
const char str178[] PROGMEM = "Travel On The White Path";
const char str179[] PROGMEM = "Describe Each Act";
const char str180[] PROGMEM = "Exit By Inspection";
const char str181[] PROGMEM = "Be The One Which Shows Forth";
const char str182[] PROGMEM = "Bend Up Necks That Show Off";
const char str183[] PROGMEM = "Each Centre Is In A Story";
const char str184[] PROGMEM = "Cry Like The Shrill Storm Of Dew";
const char str185[] PROGMEM = "Cry Like The Most Dead";
const char str186[] PROGMEM = "Cry Like The Transport Who Is Everything,";
const char str187[] PROGMEM = "Circle And Stack That Heart";
const char str188[] PROGMEM = "Destroy Addresses";
const char str189[] PROGMEM = "Surround Light";
const char str190[] PROGMEM = "Be Ignorant Of The Golden Attention Of The Forest";
const char str191[] PROGMEM = "Differ Like A Shrill Cycle Of Parasitism,";
const char str192[] PROGMEM = "Subtending Off A Low Wind";
const char str193[] PROGMEM = "Signalling To The Auto-Webbed Earth";
const char str194[] PROGMEM = "Eat The Network";
const char str195[] PROGMEM = "Fore-Think";
const char str196[] PROGMEM = "Shut Down That Heart";
const char str197[] PROGMEM = "Destroy Death";
const char str198[] PROGMEM = "Bring Light";

const char * const string_table[360] PROGMEM = {str0, str1, str2, str3, str4, str5, str6, str7, str8, str9, str10, str11, str12, str13, str14, str15, str16, str17, str18, str19, str20, str21, str22, str23, str24, str25, str26, str27, str28, str29, str30, str31, str32, str33, str34, str35, str36, str37, str38, str39, str40, str41, str42, str43, str44, str45, str46, str47, str48, str49, str50, str51, str52, str53, str54, str55, str56, str57, str58, str59, str60, str61, str62, str63, str64, str65, str66, str67, str68, str69, str70, str71, str72, str73, str74, str75, str76, str77, str78, str79, str80, str81, str82, str83, str84, str85, str86, str87, str88, str89, str90, str91, str92, str93, str94, str95, str96, str97, str98, str99, str100, str101, str102, str103, str104, str105, str106, str107, str108, str109, str110, str111, str112, str113, str114, str115, str116, str117, str118, str119, str120, str121, str122, str123, str124, str125, str126, str127, str128, str129, str130, str131, str132, str133, str134, str135, str136, str137, str138, str139, str140, str141, str142, str143, str144, str145, str146, str147, str148, str149, str150, str151, str152, str153, str154, str155, str156, str157, str158, str159, str160, str161, str162, str163, str164, str165, str166, str167, str168, str169, str170, str171, str172, str173, str174, str175, str176, str177, str178, str179, str180, str181, str182, str183, str184, str185, str186, str187, str188, str189, str190, str191, str192, str193, str194, str195, str196, str197, str198};  

//static const uint8_t readme_contents[] PROGMEM = README_CONTENTS;

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

          .Checksum        = FAT_CHECKSUM('I','N','V','O','K','E',' ',' ','T','X','T'),

          .Unicode1        = 'I',
          .Unicode2        = 'N',
          .Unicode3        = 'V',
          .Unicode4        = 'O',
          .Unicode5        = 'K',
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
          .Filename        = "INVOKE  ",
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

const char * get_string_N(int n){
	const char * p_str;
	p_str = (const char *)pgm_read_word(&string_table[n]);
	return p_str;
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
  TimeDate_t CurrentTimeDate;

  int x=0, c=0;
  //  char readbuf[66];
  uint8_t reading=0, blah;
  char charr;
double RA, Dec,  topRA, topDec,  LST, HA, Az, El, dist;
  
  /* Range check the write request - abort if requested block is not within the
   * virtual firmware file sector range */
  if (!((BlockNumber >= FileStartBlock) && (BlockNumber <= FileEndBlock)))
    return;

  //  #if (FLASHEND > 0xFFFF)
  //  uint_farptr_t FlashAddress = (uint_farptr_t)readme_contents + (uint_farptr_t)(BlockNumber - FileStartBlock) * VIRTUALFAT_SECTOR_SIZE_BYTES;
  //  #else
  //  uintptr_t FlashAddress = (uintptr_t)readme_contents + (uintptr_t)(BlockNumber - FileStartBlock) * VIRTUALFAT_SECTOR_SIZE_BYTES;
  //  #endif

  // this would be where we generate adventure texts
  // based on RTC and moon.c

  // we would have a set of invocations in FLASH that would be re-jumbled into 512 bytes and output here!
  
  //  double ecliptic = moon2(2021, 9, 7, 23+5/60., 12.41285, 52.51854);
  
  RTC_GetTimeDate(&CurrentTimeDate);
  int year=2000+CurrentTimeDate.Year;
  moon2(year, CurrentTimeDate.Month, CurrentTimeDate.Day, (CurrentTimeDate.Hour-2)+(CurrentTimeDate.Minute/60.), 12.41285, 52.51854,
	&RA, &Dec, &topRA, &topDec, &LST, &HA, &Az, &El, &dist); // +02:00 GMT (DST) Thu 12:46 pm CEST - so we need to subtract 2 hours to get correct calculation
  //  now we decided to use azimuth of 360 with 360 phrases
  // moon2(2021, 9, 16, 10+47/60., 12.41285, 52.51854,
  //       &RA, &Dec, &topRA, &topDec, &LST, &HA, &Az, &El, &dist); // +02:00 GMT (DST) Thu 12:46 pm CEST - so we need to subtract 2 hours to get correct calculation

  //  srandom((int)ecliptic);
  //  usb_serial_writeln_dec16((int)ecliptic); // now working YES!!!!!

  
  const char *charry;
  
  if (Read)
  {
    
    // Read out the mapped block of data from the device's FLASH 
    /*    for (uint16_t i = 0; i < VIRTUALFAT_SECTOR_SIZE_BYTES; i++) // 512
    {
        #if (FLASHEND > 0xFFFF)
        BlockBuffer[i] = pgm_read_byte_far(FlashAddress++);
      #else
        BlockBuffer[i] = pgm_read_byte(FlashAddress++);
      #endif
      //      BlockBuffer[i]="i";
    }
    }*/

      while(x<512){
    // read into buffer largest size of phrase
    if (reading==0){
      blah=((int)Az+x)%198;   
      charry=get_string_N(blah);
      reading=1; c=0;
    }
    charr=pgm_read_byte(charry++);
    
    if (charr=='\0'){
      BlockBuffer[x++]='\n';
      reading=0; 
    }
    else      BlockBuffer[x++]=charr;
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
