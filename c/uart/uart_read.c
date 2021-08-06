#include <avr/io.h>
#include <stdint.h>

#define BAUD_RATE_115200  8
#define BAUD_RATE_9600 103

int main()
{
  uint16_t ubrr = BAUD_RATE_9600;

	DDRB |= _BV(DDB5);        /* Led rojo, salida */

  /* Configuración el baud-rate */
  UBRR0H = (ubrr >> 8) & 0xFF;   /* Byte más significativo */
  UBRR0L = ubrr & 0xFF;          /* Byte menos significativo */

  UCSR0C = _BV(UCSZ00) | _BV(UCSZ01); /* UART con trama 8N1 */
  UCSR0B |= _BV(RXEN0);     /* Habilita el receptor */

  while(1)
  {
    /* Espera a recibir un dato */
    while( !(UCSR0A & _BV(RXC0)) );

    switch(UDR0) {
      case 'r':
      case 'R':
        PORTB ^= _BV(PORTB5); /* Cambia estado de LED rojo */
        break;
    }
  }
  return 0;
}

