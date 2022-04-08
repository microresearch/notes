#define F_CPU       		 12000000
#include <avr/io.h>			
#include <avr/interrupt.h>
#include <stdio.h>
#include <avr/delay.h>
#include <stdarg.h>
#include <stdlib.h> 
#include <stdint.h>

#define UART_BAUD_RATE 9600
#define UART_BAUD_CALC(UART_BAUD_RATE,F_CPU) ((F_CPU)/((UART_BAUD_RATE)*16l)-1)

void init_uart(void)
{
  // set baud rate
  UBRRH = (uint8_t)(UART_BAUD_CALC(UART_BAUD_RATE,F_CPU)>>8);
  UBRRL = (uint8_t)UART_BAUD_CALC(UART_BAUD_RATE,F_CPU);

  // Enable receiver and transmitter; enable RX interrupt
  UCSRB = (1<<RXEN) | (1<<TXEN);

  //asynchronous 8N1
  UCSRC = (1<<URSEL) | (3<<UCSZ0);
}

static int uart_putchar(char c, FILE *stream);

static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL,_FDEV_SETUP_WRITE);

static int uart_putchar(char c, FILE *stream)
{
  loop_until_bit_is_set(UCSRA, UDRE);
  UDR = c;
  return 0;
}

int island_install(void) {
  int size = 1024;
  unsigned char *island;
  while ((island = (unsigned char *) malloc(--size)) == NULL)
    ;
  return size;
}

int main(void)
{
  unsigned int x,xx=0;
  init_uart();
  stdout = &mystdout;
  xx=island_install();
  while(1)
    {
      x=0;
      printf("island size: %d\n\r", xx);
      while(x<100)
	{
	  _delay_ms(100);x++;
	}
    }
}
