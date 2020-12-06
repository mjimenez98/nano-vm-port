#include "../../src/hal.h"
#include "../../src/out.h"
#include "../../src/vm.h"

#define Target      "(ATMega328P)"
#define VMName      "Cm Virtual Machine "
#define AppSuffix   ""
#define AppName     "cm"
#define Version     " v0.1.00.1101a "
#define Copyright   "Copyright (c) 2001-2020  Michel de Champlain"

// Copyright notice
static void CopyrightNotice() {
    VMOut_PutS(VMName);
    VMOut_PutS(AppSuffix);
    VMOut_PutS(Version);
    VMOut_PutS(Target);
    VMOut_PutN();
    VMOut_PutS(Copyright);
    VMOut_PutN();
}

// Print 1 using "pre-configured and loaded" opcode
u8 mem[] = { 0x91, 0xFF, 0x82, 0x00 };

int main(int argc, char* argv[]) {
    Hal_Init();
    CopyrightNotice();

    VM_Init(mem);
    VM_execute(mem);

    return 0;
}
