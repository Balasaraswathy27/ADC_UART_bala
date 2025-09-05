#include "UART_bala.h"
void setup() {
  usart_init();
  ADMUX = (1<<REFS0);   
  ADCSRA = (1<<ADEN) | (1<<ADSC) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
}

void loop() {
  while (ADCSRA & (1<<ADSC));
  uint16_t analogValue = ADC;  
  const float BETA = 3950;
  float temperature = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  uart.send("Temperature:");
  uart.send(temperature);
  uart.send("C");
  uart.send("\r\n");
  delay(500);
  ADCSRA |= (1<<ADSC);
}
