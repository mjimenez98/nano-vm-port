#include "hal_Loader.h"

//#include "../../src/out.h"
#include "bsl_Uart.h"

u8 hal_Loader(u8 mem[MemMax]) {
    counter = 0;

    while (1) {
        mem[counter] = readInstruction();

        if (mem[counter] == 0)
            break;
        if (counter == 35)
            return 0xFF;    // Full memory TODO: replace for correct opcode

//        VMOut_PutU(mem[counter]);
//        VMOut_PutU(counter);

        counter += 1;
    }

    return 0x40;    // Success

}
