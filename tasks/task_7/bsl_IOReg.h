#ifndef NANO_VM_PORT_BSL_IOREG_H
#define NANO_VM_PORT_BSL_IOREG_H

#include "../../src/BSL/_stdtype.h"

u32  bsl_IOReg_Read (u32 ioreg);
void bsl_IOReg_Write(u32 ioreg, u32 value);

#endif //NANO_VM_PORT_BSL_IOREG_H
