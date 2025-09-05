#ifndef UART_BALA_H
#define UART_BALA_H

#include <avr/io.h>
#include <stdlib.h>
#define fosc 16000000UL
#define BR 9600
#define MYUBBRN ((fosc/(16UL*BR))-1)

void usart_init();
void transmitt_data(unsigned char data);
unsigned char receiver();

class myuart {
  public:
    void send(char *str);
    void send(int n);
    void send(float f);
};

extern myuart uart;

#endif
