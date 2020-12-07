avr-gcc -Os -Wall -DF_CPU=16000000UL -mmcu=atmega328p -DOnNano hal_TestLoader.c bsl_Uart.c hal_Loader.c ../../src/hal.c ../../src/out.c ../../src/vm.c ../../src/vmstack.c ../../src/_cout.c ../../src/_xtoa.c -o hal_TestLoader.o

avr-objcopy -O ihex -j .text -j .data hal_TestLoader.o  hal_TestLoader.hex

avrdude -c arduino -p atmega328p -b 57600 -P /dev/tty.wchusbserial1410 -D -Uflash:w:hal_TestLoader.hex:i
