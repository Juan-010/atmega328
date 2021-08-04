#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 300

int main (void)
{
  /* Inicializa el pin digital como salida */
	DDRD = 0xFF;
  int hex=0;
	while(1) 
  {
		PORTD = ~hex;    /* Enciende LED */
		_delay_ms(BLINK_DELAY_MS);
    if(++hex > 0xFF)
      hex = 0;

	}
	return 0;
}

