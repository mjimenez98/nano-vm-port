#include "hal_interman.h"

#ifdef OnNano

#include <avr/io.h>
#include <avr/interrupt.h>

void Interrupt_Disable(void) {
    cli();
}

void Interrupt_Enable(void) {
    sei();
}

u16 Interrupt_SaveAndDisable(void) {
    u16 saveStatus = SREG;
    Interrupt_Disable();

    return saveStatus;
}

void Interrupt_Restore(u16 flags) {
    SREG = flags;
}

/*
Out of scope
void Interrupt_SetVector(u8 number, u32 handlerAddr) { }
u32 Interrupt_GetVector(u8 number) { return 1; }
*/

#endif
