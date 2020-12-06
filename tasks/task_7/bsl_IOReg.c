#include "bsl_IOReg.h"

#ifdef onTarget
#include <avr/io.h>

u32 bsl_IOReg_Read (u32 ioreg) {
    // Return the contents of the register passed to the function
     return (PINB & (1 << ioreg));
}

void bsl_IOReg_Write(u32 ioreg, u32 value) {
    // Set the register to the value given to the function
     *(volatile uint8_t *) ioreg = value;
}
#endif

