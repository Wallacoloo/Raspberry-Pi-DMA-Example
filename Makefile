CC := gcc
CFLAGS := -g

all: dma-example
	
dma-example: dma-example.c
	$(CC) $(CFLAGS) -o dma-example dma-example.c
	
clean:
	rm -rf dma-example
	
.PHONY: clean
