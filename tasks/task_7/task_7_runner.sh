avr-gcc -Os -Wall -DF_CPU=16000000UL -mmcu=atmega328p -DOnNano bsl_TestIOReg0.c bsl_IOReg.c bsl_Uart.c hal_Loader.c ../../src/hal.c ../../src/out.c ../../src/vm.c ../../src/vmstack.c ../../src/_cout.c ../../src/_xtoa.c -o bsl_TestIOReg0.o

avr-objcopy -O ihex -j .text -j .data bsl_TestIOReg0.o  bsl_TestIOReg0.hex

avrdude -c arduino -p atmega328p -b 57600 -P /dev/tty.wchusbserial1410 -D -Uflash:w:bsl_TestIOReg0.hex:i
