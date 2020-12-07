#include "bsl_Uart.h"

#ifdef OnNano

#include <avr/io.h>

#define FOSC 16000000
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

char readInstruction() {
    // Wait until data is received
    while (!(UCSR0A & (1 << RXC0)));

    // Read the data from the RX buffer
    char input = UDR0;

    // Wait until buffer is empty
    while (!(UCSR0A & (1 << UDRE0)));

    return input;
}

#endif
