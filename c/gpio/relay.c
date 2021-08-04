#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 300

int main (void)
{
  /* Inicializa el pin digital como salida */
	DDRD = 0xFF;

	while(1) 
  {
		PORTD = 0xFF;    /* Enciende LED */
		_delay_ms(BLINK_DELAY_MS);

		PORTD &= 0;   /* Apaga LED */
		_delay_ms(BLINK_DELAY_MS);
	}
	return 0;
}

