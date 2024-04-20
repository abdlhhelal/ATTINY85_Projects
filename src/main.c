#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


ISR(INT0_vect)
{
	PORTB |= (1<<PB1);
	_delay_ms(1000);
	PORTB &= ~(1<<PB1);
}

int main(void) {

	DDRB |= (1<<PB1);
	DDRB &= ~(1<<PB2);
	PORTB &= ~(1<<PB1);
	PORTB |= (1<<PB2);
	GIMSK |= (1<<INT0);
	MCUCR |= (1<<ISC00);
	MCUCR &= ~(1<<ISC01);
	sei();
    while (1) {
    }
}
