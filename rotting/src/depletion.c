/*

Enrichment and depletion...

- fast interrupt to work through buffer and output bits on pin XX or just a loop/delay

- either loop with delay and edge trigger or interrupt 400 times per second

we check for bit (if we do not already have one in progress) over 1/200 second

if bit==0 ... then wait for a bit and set it, write into circular buffer

// we need interrupts, edge, delays, toggles

// do we need to mix assembly...

//////

refs:

https://blog.mark-stevens.co.uk/2014/06/bare-metal-gpio-raspberry-pi/ ???

https://wiki.osdev.org/ARM_RaspberryPi_Tutorial_C

https://github.com/bztsrc/raspi3-tutorial

https://github.com/dwelch67/raspberrypi

for pi2? http://www.valvers.com/open-software/raspberry-pi/step02-bare-metal-programming-in-c-pt2/

for pi2? with code: https://github.com/BrianSidebotham/arm-tutorial-rpi

start.elf, bootcode: https://github.com/raspberrypi/firmware/tree/master/boot

https://www.raspberrypi.org/forums/viewtopic.php?t=202861

https://www.instructables.com/id/Bare-Metal-Raspberry-Pi-3Blinking-LED/

*/
