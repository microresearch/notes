/*
    Part of the Raspberry-Pi Bare Metal Tutorials
    https://www.valvers.com/rpi/bare-metal/
    Copyright (c) 2013-2018, Brian Sidebotham

    This software is licensed under the MIT License.
    Please see the LICENSE file included with this software.

*/
/*
    Interrupts example, show how to use the interrupt controller and to load
    the vector table at runtime.
*/

#include <string.h>
#include <stdlib.h>

#include "rpi-gpio.h"
#include "rpi-armtimer.h"
#include "rpi-systimer.h"
#include "rpi-interrupts.h"

extern void _enable_interrupts(void);

#define GPIO_BASE       0x20200000UL

unsigned char memory[1024*1024];

volatile unsigned int* gpio = (unsigned int*)GPIO_BASE;

/** Main function - we'll never return from here */
void kernel_main( unsigned int r0, unsigned int r1, unsigned int atags )
{
  uint32_t ourcounter = 0;
  uint32_t counter;
  //  memory = malloc( 1024 * 1024 * sizeof( unsigned char ) );

  // fill memory with ones and zeroes for testing
  for (counter=0;counter<(1024*1024); counter++){
    memory[counter]=0;
  }

  /* Write 1 to the LED init nibble in the Function Select GPIO
       peripheral register to enable LED pin as an output */
  //    RPI_GetGpio()->LED_GPFSEL |= LED_GPFBIT;

    gpio[LED_GPFSEL] |= ( 1 << LED_GPFBIT );
    gpio[ALED_GPFSEL] |= ( 1 << ALED_GPFBIT );

    // set up pin for input - clear bit
    gpio[IN_GPFSEL] &= ~(1 << IN_GPFBIT);
    gpio[IN_GPFSEL] &= ~(1 << (IN_GPFBIT+1));
    gpio[IN_GPFSEL] &= ~(1 << (IN_GPFBIT+2));
    // set rising edge bit
    //    gpio[IN_GPREN] |= ( 1 << IN_GPRENBIT );
    // set a falling edge.
    gpio[IN_GPFEN] |= ( 1 << IN_GPRENBIT );
  
    /* Enable the timer interrupt IRQ */
    RPI_GetIrqController()->Enable_Basic_IRQs = RPI_BASIC_ARM_TIMER_IRQ;

    /* Setup the system timer interrupt */
    /* Timer frequency = Clk/256 * 0x400 */
    // see what frequency we get here?
    RPI_GetArmTimer()->Load = 0x80; // was 0x100= 250 Khz - 581 KHz is limit for code
    RPI_GetArmTimer()->PreDivider = 1; // 250 MHZ! (0x400 *1024) - was 1

    // but what we have is 61 KHz?
    // timer_clock = apb_clock/(pre_divider+1) = apb_clock/2=
    // so work backwards from 61000*2=122 000*256= 31 232 000 = 31 MHz

    
    /* Setup the ARM Timer */
    RPI_GetArmTimer()->Control =
            RPI_ARMTIMER_CTRL_23BIT |
            RPI_ARMTIMER_CTRL_ENABLE |
            RPI_ARMTIMER_CTRL_INT_ENABLE |
            RPI_ARMTIMER_CTRL_PRESCALE_1;

    /* Enable interrupts! */
    _enable_interrupts();
    //      LED_ON();

    /* Never exit as there is no OS to exit to! */
    while(1)
    {
      // go for a falling edge,,,
      // testing - see if there's a rising edge bit and if so light LED         - LED_ON();
      // // and we read rising edge with GPIO_GPEDS0 bit 21 and clear it by writing a 1 there!

      //      if ((gpio[GPIO_GPEDS0]&(1<<IN_GPRENBIT))==(1<<IN_GPRENBIT)) LED_ON(); // this works as long as interrupt is not too fast
      //            else LED_OFF();
      //      LED_ON();
      //      LED_ON();

      // test for falling edge -

      /*

--- clear gpeds bit
--- delay for 1/400th sec= 2500 microseconds
--- is GPEDSn event detected?
--- if so write a one to memory
--- if not write a zero
--- inc. memory bit

      */
      gpio[GPIO_GPEDS0]&=(1 << IN_GPRENBIT); // clear it by writing a 1
      RPI_WaitMicroSeconds(2500);
      //      if ((gpio[GPIO_GPEDS0]&(1<<IN_GPRENBIT))==(1<<IN_GPRENBIT)) LED_ON(); // this works as long as interrupt is not too fast
      //      else LED_OFF();

      if ((gpio[GPIO_GPEDS0]&(1<<IN_GPRENBIT))==(1<<IN_GPRENBIT)) {
	memory[ourcounter++]=1;
	ALED_ON();
      }
      else
	{
	memory[ourcounter++]=0;
	ALED_OFF();
	}


      if (ourcounter&0x100000) ourcounter=0;

      
      
    }
}
