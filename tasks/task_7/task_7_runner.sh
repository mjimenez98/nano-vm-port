avr-gcc -Os -Wall -DF_CPU=16000000UL -mmcu=atmega328p -DOnNano bsl_TestIOReg0.c bsl_IOReg.c ../task_5/bsl_Uart.c ../../src/HAL/hal.c ../../src/HAL/out.c ../../src/vm.c ../../src/vmstack.c ../../src/BSL/_cout.c ../../src/BSL/_xtoa.c -o bsl_TestIOReg0.o

avr-objcopy -O ihex -j .text -j .data bsl_TestIOReg0.o  bsl_TestIOReg0.hex

avrdude -c arduino -p atmega328p -b 57600 -P /dev/tty.usbserial-1420 -D -Uflash:w:bsl_TestIOReg0.hex:i
