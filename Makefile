CC=gcc
CFLAGS=-g $(DEFINES)

all: help
rpi1: DEFINES:=$(DEFINES) -DRPI_V1
rpi2: DEFINES:=$(DEFINES) -DRPI_V2
rpi3: DEFINES:=$(DEFINES) -DRPI_V3
rpi1 rpi2 rpi3: dma-example dma-gpio

dma-example: dma-example.c
	$(CC) $(CFLAGS) -o dma-example dma-example.c
dma-gpio: dma-gpio.c
	$(CC) $(CFLAGS) -O2 -std=gnu99 -o dma-gpio dma-gpio.c -lrt
	
clean:
	rm -rf dma-example dma-gpio

help:
	@echo "Type make <target> where target is one of:"
	@echo "  * rpi1 (for the original Raspberry Pi A/B/A+/B+)"
	@echo "  * rpi2 (for the Raspberry Pi A2/B2)"
	@echo "  * rpi3 (for Raspberry Pi B3)"
	@echo "  Pi Zero users will most likely have success building for rpi1, since the Pi Zero uses its chipset."
	@echo "  Note: rpi2/3/zero support should be considered experimental."
	
.PHONY: clean help
