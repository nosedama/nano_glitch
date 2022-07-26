#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "usart.h"
 
#define BLINK_DELAY_MS (100)
#define LOOP_ITERATIONS (100)
 
int main (void)
{
	volatile uint32_t i, j, count, repetition;

	/* Set pin 5 of PORTB for output*/
	DDRB |= _BV(DDB5);

	uart_init(BAUD_CALC(115200));
	stdout = &uart0_io;
	stdin = &uart0_io;

	/* Enable interrupts (needed for the uart library) */
	sei();

	repetition = 0;

	while(1) {
		/* Set trigger high */
		PORTB |= _BV(PORTB5);

		count = 0;
		for(i=0; i<LOOP_ITERATIONS; i++) {
			for(j=0; j<LOOP_ITERATIONS; j++) {
				count++;
			}
		}

		/* Set trigger low */
		PORTB &= ~_BV(PORTB5);
		//_delay_ms(BLINK_DELAY_MS);

		printf("%lu %lu %lu %lu\r\n", i, j, count, repetition++);
	}
}
