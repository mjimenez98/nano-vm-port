#include "hal_interman.h"

#ifdef onTarget

#include <avr/io.h>
#include <avr/interrupt.h>

void Interrupt_Disable(void) {
    cli();
}

void Interrupt_Enable(void) {
    sei();
}

u16 Interrupt_SaveAndDisable(void) {
    u16 ram = (*(u16 *) 0x100);
//    u16 ram = SRAM;

    Interrupt_Disable();

    return ram;
}

void Interrupt_Restore(u16 flags) {
    (*(u16 *) (0x100) = flags);
//    SRAM = flags;
    Interrupt_Enable();
}

/*
Out of scope
void Interrupt_SetVector(u8 number, u32 handlerAddr) { }
u32 Interrupt_GetVector(u8 number) { return 1; }
*/

#endif
