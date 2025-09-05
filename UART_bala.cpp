#include "UART_bala.h"

void usart_init(){
  UBRR0L=MYUBBRN;
  UBRR0H=MYUBBRN>>8;
  UCSR0C=(1<<UCSZ00)|(1<<UCSZ01);
  UCSR0B=(1<<TXEN0)|(1<<RXEN0);
}

void transmitt_data(unsigned char data){
  while(!(UCSR0A & (1<<UDRE0)));
  UDR0=data;
}

unsigned char receiver(){
  while(!(UCSR0A & (1<<RXC0)));
  return UDR0;
}

void myuart::send(int n){
  if(n == 0){          
    transmitt_data('0');
    return;
  }

  if(n < 0){         
    transmitt_data('-');
    n = -n;
  }
  int num = n;
  int count = 1;
  unsigned char d;
 
  while(n > 0){
    count = count * 10;
    n /= 10;
  }
  count /= 10;

  while(count > 0){
     d = num / count;
     num = num % count;
     transmitt_data(d + '0');
     count /= 10;
  }
}
void myuart::send(float f) {
    char buf[20];
    dtostrf(f, 0,2, buf);
    send(buf);
  }

void myuart::send(char *str){
  while(*str!='\0'){
    transmitt_data(*str);
    str++;
  }
}

myuart uart;
