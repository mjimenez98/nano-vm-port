#ifndef NANO_VM_PORT_HAL_LOADER_H
#define NANO_VM_PORT_HAL_LOADER_H

#include "../../src/BSL/_stdtype.h"

#define MemMax 36

u32 counter;

u8 hal_Loader(u8 mem[MemMax]);

#endif //NANO_VM_PORT_HAL_LOADER_H
