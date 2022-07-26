# Tooling

## Setup
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

## Build
```bash
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o blink.o blink.c
avr-gcc -mmcu=atmega328p blink.o -o blink
avr-objcopy -O ihex -R .eeprom blink blink.hex
```

## Flash
```bash
avrdude -F -V -c jtag3isp -p ATMEGA328P -U flash:w:blink.hex
```

# Information Gathering

## Fuses
Taken from p.291:
- Extended Fuse: 0xFF (default)
- High Fuse: 0xD9 (default)
- Low Fuse: 0xBF (CKOUT, slowest start-up, 16 MHz low-power crystal)

```
avrdude -F -V -c jtag3isp -p ATMEGA328P -U efuse:w:0xff:m
avrdude -F -V -c jtag3isp -p ATMEGA328P -U hfuse:w:0xd9:m
avrdude -F -V -c jtag3isp -p ATMEGA328P -U lfuse:w:0xbf:m
```

Check fuses:
```
make show_fuses
```

## Oscillator
- XTAL1 is the input of the oscillator circuitry (p.44)
- Maximum allowed variation of frequency for stable operation: 2% (p.44)


# Sources
`https://wellys.com/posts/avr_c_linux/`
`https://github.com/jnk0le/AVR-UART-lib`
