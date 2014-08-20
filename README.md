Raspberry-Pi-DMA-Example
========================

Simplest example of copying memory from one region to another using DMA

Just type `make`, and then `sudo ./dma-example` (must use sudo to get permissions for writing to DMA peripheral)

The example simply copies the string "hello world" from one place in memory to another, through the use of the Raspberry Pi's DMA peripheral.

Some code, namely for translating virtual addresses to physical ones, was based on that found in the Raspberry Pi FM Transmitter which I *think* is by either Oliver Mattos or Oskar Weigl, but their website has been down for a while now. Some of the code can still be found here: http://www.raspians.com/turning-the-raspberry-pi-into-an-fm-transmitter/

License
======

I'm putting this code in the public domain. However, the two functions - `makeVirtPhysPage` and `freeVirtPhysPage` - were based on code found in the FM Transmitter, which was GPL-licensed. If you want to use this code under a non-GPL license, I would recommend replacing those functions with your own code, just to be extra safe. **Disclaimer**: I am not a lawyer.
