avr-gcc -Os -Wall -DF_CPU=16000000UL -mmcu=atmega328p -DOnNano admin.c ../../src/HAL/hal.c ../../src/HAL/out.c ../../src/vm.c ../../src/vmstack.c ../../src/BSL/_cout.c ../../src/BSL/_xtoa.c -o _cout.o

avr-objcopy -O ihex -j .text -j .data _cout.o  _cout.hex

avrdude -c arduino -p atmega328p -b 57600 -P /dev/tty.usbserial-1410 -D -Uflash:w:_cout.hex:i
