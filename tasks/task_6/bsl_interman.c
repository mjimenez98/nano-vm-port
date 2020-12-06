#include "bsl_interman.h"

#ifdef onTarget

#include <avr/io.h>

bool GetStatusReg() {
    return SREG;
}

#endif
