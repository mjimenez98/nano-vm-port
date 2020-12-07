avr-gcc -Os -Wall -DF_CPU=16000000UL -mmcu=atmega328p -DOnNano tout.c ../../src/HAL/hal.h ../../src/HAL/out.h ../../src/vm.h -o tout.o

avr-objcopy -O ihex -j .text -j .data tout.o  tout.hex

avrdude -c arduino -p atmega328p -b 57600 -P /dev/tty.wchusbserial1410 -D -Uflash:w:tout.hex:i