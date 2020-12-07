/* _cout.c - Implementation of a Console for Cm Hardware Abstract Layer for Output Interface.
//
// Copyright (C) 1999-2020 by Michel de Champlain
//
*/

#include "_outdesc.h"

#if ConsoleOutputWithPrintf

static void COut_PutB(bool b)        { printf("%s", b ? "true" : "false"); }
static void COut_PutC(char c)        { printf("%c", c); }
static void COut_PutS(const char* s) { printf("%s", s); }
static void COut_PutI(i32  i)        { printf("%ld", i); }
static void COut_PutU(u32  u)        { printf("%lu", u); }
static void COut_PutX(u32  u)        { printf("%08lX", u); } // To make hex output always aligned to 8 hex digits.
static void COut_PutN(void)          { printf("\n"); }

#else
#include "_xtoa.h"

static char  buf[12];                /* to cover max size (12) "i32" (10+sign+null) */

#ifdef OnNano

#include <avr/io.h>

#define FOSC 16000000
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

static void COut_Init() {
    // Set baud rate
    UBRR0H = (MYUBRR >> 8);
    UBRR0L = MYUBRR;

    // Enable receiver and transmitter
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);

    // Set frame: 8data, 1 stop bit
    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}

void Console_Putchar(char c) {
    // Wait until buffer is empty
    while (!(UCSR0A & (1 << UDRE0)));

    // Send char
    UDR0 = c;
}

#else

// External refs to 'console.c' without
void Console_Putchar(char  c);

#endif

static void COut_PutC(char c)        { Console_Putchar(c); }
static void COut_PutS(const char* s) { while (*s) Console_Putchar(*s++); }
static void COut_PutI(i32  i)        { System_itoa(i, buf); COut_PutS(buf); }
static void COut_PutU(u32  u)        { System_utoa(u, buf, 10); COut_PutS(buf); }
static void COut_PutX(u32  x)        { System_utoa(x, buf, 16); COut_PutS(buf); } // Same behavior as Dos16 VM: 
                                                                                   // Hex alpha in upppercase
static void COut_PutN(void)          { Console_Putchar('\n'); }
static void COut_PutB(bool b)        { COut_PutS(b ? "true" : "false"); }

#endif

static IVMOutDesc cout = {
    COut_PutB,
    COut_PutC,
    COut_PutI,
    COut_PutU,
    COut_PutS,
    COut_PutX,
    COut_PutN
};

static bool init = 0;

IOut Out_GetFactory(const char* whichOne) {
    if (!init) {      // To make sure it will be done only once.
        whichOne = 0; // To avoid the warning on the unreferenced formal parameter.

        #ifdef OnNano
        COut_Init();
        #endif

        init = true;
    }

    return &cout;
}

// --------------- Test unit ---------------

#ifdef DebugXtoa

static void TestCout(void) {
    COut_PutS("Task 3 Test\n");
    COut_PutS("123456789ABCDEF\n");
    COut_PutN();
}

int main (void) {
    Out_GetFactory("");
    TestCout();

    return 0;
}

#endif
