CC := gcc
CFLAGS := -g

all: dma-example dma-gpio
	
dma-example: dma-example.c
	$(CC) $(CFLAGS) -o dma-example dma-example.c
dma-gpio: dma-gpio.c
	$(CC) $(CFLAGS) -O2 -std=gnu99 -o dma-gpio dma-gpio.c -lrt
	
clean:
	rm -rf dma-example dma-gpio
	
.PHONY: clean
