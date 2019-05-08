#Variable Definition
FileName = PrintString
MMCU=atmega328p
SerialCom =/dev/ttyAMA0
CPUFlag=12000000L

all:  	build link copy flash 

build : 
	avr-gcc -g -Os -mmcu=$(MMCU) -DF_CPU=12000000L -c $(FileName).c -o $(FileName).o

link:
	avr-gcc -mmcu=$(MMCU) -DF_CPU=12000000L -o $(FileName).elf $(FileName).o

copy : 
	avr-objcopy -O ihex -R .eeprom $(FileName).elf $(FileName).hex

flash : 
	avrdude -F -V -c gpio -p $(MMCU) -P $(SerialCom) -b 9600 -U flash:w:$(FileName).hex