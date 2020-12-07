#ifndef NANO_VM_PORT_HAL_INTERMAN_H
#define NANO_VM_PORT_HAL_INTERMAN_H

#include "../../src/BSL/_stdtype.h"

void Interrupt_Disable(void);
void Interrupt_Enable(void);
u16 Interrupt_SaveAndDisable(void);
void Interrupt_Restore(u16 flags);

// Out of scope
// void Interrupt_SetVector(u8 number, u32 handlerAddr); u32 Interrupt_GetVector(u8 number);

#endif //NANO_VM_PORT_HAL_INTERMAN_H
