# makefile, written by guido socher
MCU=atmega168
#MCU=at90s4433
CC=avr-g++
#CEXTRA=-Wa,-adhlns=$(<:.c=.lst)
#EXTERNAL_RAM = -Wl,--defsym=__heap_start=0x801100,--defsym=__heap_end=0x80ffff
#EXTERNAL_RAM = -Wl,-Tdata=0x801100,--defsym=__heap_end=0x80ffff
LDFLAGS  = -mmcu=${MCU} -Wl,-u, -lm
#LDFLAGS  = -mmcu=${MCU} -Wl,-u,vfprintf -lprintf_flt -lm
OBJCOPY=avr-objcopy
# optimize for size:
#CFLAGS=-g -mmcu=$(MCU) -Wall -Wstrict-prototypes -mcall-prologues ${CEXTRA}
CFLAGS=-mmcu=$(MCU) -Os -D'AVR_IS'
DEVICE = m168
AVRDUDE = avrdude -c usbasp -p $(DEVICE)
FUSEH = 0xdf
FUSEL = 0xf7


#-------------------
all: heatsick.hex
#-------------------
help: 
	@echo "Usage: make all|load|load_pre|rdfuses|wrfuse1mhz|wrfuse4mhz|wrfusecrystal"
	@echo "Warning: you will not be able to undo wrfusecrystal unless you connect an"
	@echo "         external crystal! uC is dead after wrfusecrystal if you do not"
	@echo "         have an external crystal."
#-------------------
heatsick.hex : heatsick.out 
	$(OBJCOPY) -R .eeprom -O ihex heatsick.out heatsick.hex 
#	$(OBJCOPY) -O ihex heatsick.out heatsick.hex 
#heatsick.out : heatsick.o 
#	$(CC) $(CFLAGS) -o heatsick.out -Wl,-Map,heatsick.map heatsick.o 
heatsick.out : heatsick.o 
	$(CC) ${LDFLAGS} $(CFLAGS) -o heatsick.out  heatsick.o 


heatsick.o : heatsick.c 
	$(CC) $(CFLAGS) -Os -c heatsick.c

heatsick.elf: heatsick.o
	$(CC) ${LDFLAGS} $(CFLAGS) -o heatsick.elf heatsick.o

disasm:	heatsick.elf
	avr-objdump -d noise.elf

fuse:
	$(AVRDUDE) -F -U hfuse:w:$(FUSEH):m -U lfuse:w:$(FUSEL):m

flash: all
	$(AVRDUDE) -F -U flash:w:heatsick.hex:i



#-------------------
clean:
	rm -f *.o *.map *.out *t.hex
#-------------------
