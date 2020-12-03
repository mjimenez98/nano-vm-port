/* hal_TestLoader.c - Test Loader implementation for HAL using bsl_Uart.c
//
// Copyright (C) 2020 by Michel de Champlain
//
*/

#include "../../src/_stdtype.h"

#include "../../src/hal.h"
#include "hal_Loader.h"

#include "../../src/out.h"
#include "../../src/vm.h"

#define Target      "(ATMega328P)"
#define VMName      "Cm Virtual Machine "
#define AppSuffix   ""
#define AppName     "cm"
#define Version     " v0.1.00.1101a "
#define Copyright   "Copyright (c) 2001-2020  Michel de Champlain"

// Banner = VMname AppSuffix Version Copyright
static void DisplayBanner() {
    VMOut_PutS(VMName); VMOut_PutS(AppSuffix); VMOut_PutS(Version); VMOut_PutS(Target); VMOut_PutN();
    VMOut_PutS(Copyright); VMOut_PutN();
}

#define Success 0x40
#define Ack 0xCC

static u8 mem[MemMax];

int main() {
    u8 status;

    Hal_Init();

    while (1) {
        if ((status = hal_Loader(mem)) == Success) {
            DisplayBanner();
            VM_Init(mem);
            VM_execute(mem);

            // Send an Ack to tell the Host that program's execution is done.
            VMOut_PutC((char) Ack);
            VMOut_PutC((char) 0);
        } else {
            VMOut_PutS("Loader error: "); VMOut_PutX(status); VMOut_PutN();
            return -1;
        }
    }

    return 0;
}
