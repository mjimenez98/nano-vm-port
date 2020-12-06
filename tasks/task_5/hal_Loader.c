#include "hal_Loader.h"
#include "bsl_Uart.h"

#include "../../src/out.h"

u8 hal_Loader(u8 mem[MemMax]) {
    counter = 0;

    while (1) {
        mem[counter] = readInstruction();

        VMOut_PutC(readInstruction());
        VMOut_PutN();

        if (mem[counter] == 0)
            break;
//        if (counter == 35)
//            return 0xFF;    // Full memory TODO: replace for correct opcode
//
        if (counter == MemMax)
            break;

        counter += 1;
    }

    return 0x40;    // Success
}
