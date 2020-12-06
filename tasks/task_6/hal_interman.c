#include "hal_interman.h"

#ifdef onTarget

#include <avr/io.h>

void Interrupt_Disable(void) {
    cli();
}

void Interrupt_Enable(void) {
    // [ (Clock value / prescaler_value) * desired_time_in_seconds ] - 1
    // [ (16 000 000 / 1024) * 2.5 ] - 1 = 39062
    OCR1A = 39062;

    // CTC Mode
    TCCR1B |= (1 << WGM12);

    // Set the ISR COMPA vect
    TIMSK1 |= (1 << OCIE1A);

    // Set prescaler and start timer
    TCCR1B |= (1 << CS12) | (1 << CS10);

    // Enable interrupt
    sei();
}

u16 Interrupt_SaveAndDisable(void) {


    return 1;
}

void Interrupt_Restore(u16 flags) {

}

/*
Out of scope
void Interrupt_SetVector(u8 number, u32 handlerAddr) { }
u32 Interrupt_GetVector(u8 number) { return 1; }
*/

#endif
