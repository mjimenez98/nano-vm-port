#include "bsl_IOReg.h"

#ifdef onTarget
#include <avr.io/h>

u32 bsl_IOReg_Read (u32 ioreg) {
    // Implementation here
    DDRB &= ~(0 << ioreg);

    // Replace with actual value to return
    return ((PINB & (1 << ioreg)))
}

void bsl_IOReg_Write(u32 ioreg, u32 value) {
    // Implementation here
     DDRB = (1 << ioreg);

     // set the output to the value given to the function
     PORTB = (value << ioreg);
}



#endif

