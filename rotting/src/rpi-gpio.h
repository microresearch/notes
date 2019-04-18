/*
    Part of the Raspberry-Pi Bare Metal Tutorials
    https://www.valvers.com/rpi/bare-metal/
    Copyright (c) 2013-2018, Brian Sidebotham

    This software is licensed under the MIT License.
    Please see the LICENSE file included with this software.

*/

#ifndef RPI_GPIO_H
#define RPI_GPIO_H

#include "rpi-base.h"

/** The base address of the GPIO peripheral (ARM Physical Address) */
#define RPI_GPIO_BASE       ( PERIPHERAL_BASE + 0x200000UL )

/* Different Raspberry pi models have the ACT LED on different GPIO pins. The RPI3 doesn't have
   access to the ACT LED through a GPIO pin can so can't be used in this tutorial, but the RPI3B+
   does have the ACT LED on a GPIO pin again and so can be used with this tutorial! */

#if defined( RPI1 ) && !defined( IOBPLUS )

    /* Very early models of the RPi including the Model A or B had ACT LED available on GPIO */
    #define LED_GPFSEL      GPFSEL1
    #define LED_GPFBIT      18
    #define LED_GPSET       GPSET0
    #define LED_GPCLR       GPCLR0
    #define LED_GPIO_BIT    16
    #define LED_ON()        do { RPI_GetGpio()->LED_GPSET = ( 1 << LED_GPIO_BIT ); } while( 0 )
    #define LED_OFF()       do { RPI_GetGpio()->LED_GPCLR = ( 1 << LED_GPIO_BIT ); } while( 0 )

#elif (defined( RPI1 ) && defined( IOBPLUS )) || defined( RPI2 ) || defined( RPI0 )

    /* The RPI1B+ and RPI2 and RPI0 (Pi Zero and ZeroW) use GPIO47 for the ACT LED  - try pin 27*/
    #define LED_GPFSEL      GPIO_GPFSEL2
    #define LED_GPFBIT      21
    #define LED_GPSET       GPIO_GPSET0
    #define LED_GPCLR       GPIO_GPCLR0
    #define LED_GPIO_BIT    27
    #define LED_ON()        do { gpio[LED_GPSET] = ( 1 << LED_GPIO_BIT ); } while( 0 )
    #define LED_OFF()       do { gpio[LED_GPCLR] = ( 1 << LED_GPIO_BIT ); } while( 0 )

// add activity pin so we can see pulses

    #define ALED_GPFSEL      GPIO_GPFSEL4
    #define ALED_GPFBIT      21
    #define ALED_GPSET       GPIO_GPSET1
    #define ALED_GPCLR       GPIO_GPCLR1
    #define ALED_GPIO_BIT    15
    #define ALED_ON()        do { gpio[ALED_GPSET] = ( 1 << ALED_GPIO_BIT ); } while( 0 )
    #define ALED_OFF()       do { gpio[ALED_GPCLR] = ( 1 << ALED_GPIO_BIT ); } while( 0 )


// set up pin 40 GPIO21 as an input with rising edge

#define IN_GPFSEL GPIO_GPFSEL2
#define IN_GPFBIT 3 // we clear this for input
#define IN_GPREN GPIO_GPREN0 // set bit to 1 to enable rising edge
#define IN_GPFEN GPIO_GPFEN0 // set to 1 for falling edge
#define IN_GPRENBIT 21 

// and we read rising edge with GPIO_GPEDS0 bit 21 and clear it by writing a 1 there!

#elif defined( RPI3 ) && defined( IOBPLUS )

    /* The RPi3B+ again made the ACT LED available on a GPIO pin (of course on yet another pin!) */
    #define LED_GPFSEL      GPFSEL2
    #define LED_GPFBIT      27
    #define LED_GPSET       GPSET0
    #define LED_GPCLR       GPCLR0
    #define LED_GPIO_BIT    29
    #define LED_ON()        do { RPI_GetGpio()->LED_GPSET = ( 1 << LED_GPIO_BIT ); } while( 0 )
    #define LED_OFF()       do { RPI_GetGpio()->LED_GPCLR = ( 1 << LED_GPIO_BIT ); } while( 0 )

#elif defined( RPI3 )

    #error The RPI3 has an ioexpander between the ACT LED and the GPU and so cannot be used in this tutorial
#endif

/***/
#define RPI_GPIO_FSEL0_00_INPUT     ( 0 )
#define RPI_GPIO_FSEL0_00_OUTPUT    ( 1 )

#define RPI_GPIO_FSEL0_01_INPUT     ( 0 << 3 )
#define RPI_GPIO_FSEL0_01_OUTPUT    ( 1 << 3 )

#define RPI_GPIO_FSEL0_02_INPUT     ( 0 << 6 )
#define RPI_GPIO_FSEL0_02_OUTPUT    ( 1 << 6 )

#define RPI_GPIO_FSEL0_03_INPUT     ( 0 << 9 )
#define RPI_GPIO_FSEL0_03_OUTPUT    ( 1 << 9 )

#define RPI_GPIO_FSEL0_04_INPUT     ( 0 << 12 )
#define RPI_GPIO_FSEL0_04_OUTPUT    ( 1 << 12 )

#define RPI_GPIO_FSEL0_05_INPUT     ( 0 << 15 )
#define RPI_GPIO_FSEL0_05_OUTPUT    ( 1 << 15 )

#define RPI_GPIO_FSEL0_06_INPUT     ( 0 << 18 )
#define RPI_GPIO_FSEL0_06_OUTPUT    ( 1 << 18 )

#define RPI_GPIO_FSEL0_07_INPUT     ( 0 << 21 )
#define RPI_GPIO_FSEL0_07_OUTPUT    ( 1 << 21 )

#define RPI_GPIO_FSEL0_08_INPUT     ( 0 << 24 )
#define RPI_GPIO_FSEL0_08_OUTPUT    ( 1 << 24 )

#define RPI_GPIO_FSEL0_09_INPUT     ( 0 << 27 )
#define RPI_GPIO_FSEL0_09_OUTPUT    ( 1 << 27 )




/** The GPIO Peripheral is described in section 6 of the BCM2835 Peripherals
    documentation.

    There are 54 general-purpose I/O (GPIO) lines split into two banks. All
    GPIO pins have at least two alternative functions within BCM. The
    alternate functions are usually peripheral IO and a single peripheral
    may appear in each bank to allow flexibility on the choice of IO voltage.
    Details of alternative functions are given in section 6.2. Alternative
    Function Assignments.

    The GPIO peripheral has three dedicated interrupt lines. These lines are
    triggered by the setting of bits in the event detect status register. Each
    bank has its’ own interrupt line with the third line shared between all
    bits.

    The Alternate function table also has the pull state (pull-up/pull-down)
    which is applied after a power down. */
typedef struct {
    rpi_reg_rw_t    GPFSEL0;
    rpi_reg_rw_t    GPFSEL1;
    rpi_reg_rw_t    GPFSEL2;
    rpi_reg_rw_t    GPFSEL3;
    rpi_reg_rw_t    GPFSEL4;
    rpi_reg_rw_t    GPFSEL5;
    rpi_reg_ro_t    Reserved0;
    rpi_reg_wo_t    GPSET0;
    rpi_reg_wo_t    GPSET1;
    rpi_reg_ro_t    Reserved1;
    rpi_reg_wo_t    GPCLR0;
    rpi_reg_wo_t    GPCLR1;
    rpi_reg_ro_t    Reserved2;
    rpi_reg_wo_t    GPLEV0;
    rpi_reg_wo_t    GPLEV1;
    rpi_reg_ro_t    Reserved3;
    rpi_reg_wo_t    GPEDS0;
    rpi_reg_wo_t    GPEDS1;
    rpi_reg_ro_t    Reserved4;
    rpi_reg_wo_t    GPREN0;
    rpi_reg_wo_t    GPREN1;
    rpi_reg_ro_t    Reserved5;
    rpi_reg_wo_t    GPFEN0;
    rpi_reg_wo_t    GPFEN1;
    rpi_reg_ro_t    Reserved6;
    rpi_reg_wo_t    GPHEN0;
    rpi_reg_wo_t    GPHEN1;
    rpi_reg_ro_t    Reserved7;
    rpi_reg_wo_t    GPLEN0;
    rpi_reg_wo_t    GPLEN1;
    rpi_reg_ro_t    Reserved8;
    rpi_reg_wo_t    GPAREN0;
    rpi_reg_wo_t    GPAREN1;
    rpi_reg_ro_t    Reserved9;
    rpi_reg_wo_t    GPAFEN0;
    rpi_reg_wo_t    GPAFEN1;
    rpi_reg_ro_t    Reserved10;
    rpi_reg_wo_t    GPPUD;
    rpi_reg_wo_t    GPPUDCLK0;
    rpi_reg_wo_t    GPPUDCLK1;
    rpi_reg_ro_t    Reserved11;
} rpi_gpio_t;

#define GPIO_GPFSEL0    0
#define GPIO_GPFSEL1    1
#define GPIO_GPFSEL2    2
#define GPIO_GPFSEL3    3
#define GPIO_GPFSEL4    4
#define GPIO_GPFSEL5    5

#define GPIO_GPSET0     7
#define GPIO_GPSET1     8

#define GPIO_GPCLR0     10
#define GPIO_GPCLR1     11

#define GPIO_GPLEV0     13
#define GPIO_GPLEV1     14

#define GPIO_GPEDS0     16
#define GPIO_GPEDS1     17

#define GPIO_GPREN0     19
#define GPIO_GPREN1     20

#define GPIO_GPFEN0     22
#define GPIO_GPFEN1     23

#define GPIO_GPHEN0     25
#define GPIO_GPHEN1     26

#define GPIO_GPLEN0     28
#define GPIO_GPLEN1     29

#define GPIO_GPAREN0    31
#define GPIO_GPAREN1    32

#define GPIO_GPAFEN0    34
#define GPIO_GPAFEN1    35

#define GPIO_GPPUD      37
#define GPIO_GPPUDCLK0  38
#define GPIO_GPPUDCLK1  39


extern rpi_gpio_t* RPI_GetGpio(void);
extern void RPI_GpioInit(void);

#endif
