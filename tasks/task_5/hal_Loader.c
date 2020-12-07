#include "hal_Loader.h"
#include "bsl_Uart.h"

#include "../../src/HAL/out.h"

u8 hal_Loader(u8 mem[MemMax]) {
    counter = 0;

    while (1) {
        // Read character from UART
        char input = readInstruction();

        VMOut_PutX(input);
        VMOut_PutC('|');
        VMOut_PutX(counter);
        VMOut_PutN();

        if (counter == 3)
            break;

        counter += 1;

//        // Save it in mem
//        mem[counter] = (u8) input;
//
//        // Increase counter
//        counter += 1;
//
//        // Break
//        if (counter == MemMax || input == '\0')
//            break;
    }

    return 0x40;    // Success
}
