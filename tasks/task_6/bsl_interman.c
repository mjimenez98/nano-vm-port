#include "bsl_interman.h"

#ifdef OnNano

#include <avr/io.h>

bool GetStatusReg() {
    return SREG;
}

#endif
