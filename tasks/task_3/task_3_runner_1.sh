avr-gcc -Os -Wall -DF_CPU=16000000UL -mmcu=atmega328p -DOnNano tvmstack.c ../../src/HAL/hal.h ../../src/HAL/out.h ../../src/vm.h -o tvmstack.o

avr-objcopy -O ihex -j .text -j .data tvmstack.o  tvmstack.hex

avrdude -c arduino -p atmega328p -b 57600 -P /dev/tty.wchusbserial1410 -D -Uflash:w:tvmstack.hex:i
