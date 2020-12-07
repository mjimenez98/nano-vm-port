avr-gcc -Os -Wall -DF_CPU=16000000UL -mmcu=atmega328p -DOnNano hal_TestInterman0.c hal_interman.c bsl_interman.c ../task_5/bsl_Uart.c ../../src/HAL/hal.c ../../src/HAL/out.c ../../src/vm.c ../../src/vmstack.c ../../src/BSL/_cout.c ../../src/BSL/_xtoa.c -o hal_TestInterman0.o

avr-objcopy -O ihex -j .text -j .data hal_TestInterman0.o  hal_TestInterman0.hex

avrdude -c arduino -p atmega328p -b 57600 -P /dev/tty.usbserial-1410 -D -Uflash:w:hal_TestInterman0.hex:i
