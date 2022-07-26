# Setup
```bash
sudo apt install gcc-avr binutils-avr gdb-avr avr-libc avrdude make git
```

Check and confirm:
```bash
avr-gcc --version
make --version
git --version
avrdude
```

# Build
```bash
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o blink.o blink.c
avr-gcc -mmcu=atmega328p blink.o -o blink
avr-objcopy -O ihex -R .eeprom blink blink.hex
```

# Flash
```bash
avrdude -F -V -c jtag3isp -p ATMEGA328P -U flash:w:blink.hex
```

# Sources
`https://wellys.com/posts/avr_c_linux/`
`https://github.com/jnk0le/AVR-UART-lib`
