#include "hal_Loader.h"
#include "bsl_Uart.h"

u8 hal_Loader(u8 mem[MemMax]) {
    counter = 0;

    while (1) {
        // Read character from UART
        char input = readInstruction();

        // Save it in mem
        mem[counter] = (u8) input;

        // Increase counter
        counter += 1;

        // Break
        if (counter == MemMax || input == '\0')
            break;
    }

    return 0x40;    // Success
}
