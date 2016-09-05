Raspberry-Pi-DMA-Example
========================

Simplest example of copying memory from one region to another using DMA ("Direct Memory Access") in userland

Just type `make <target>` where `target` is either `rpi1`, `rpi2`, or `rpi3`, and then `sudo ./dma-example` (must use sudo to get permissions for writing to DMA peripheral).
Type `make help` for more info.

The example simply copies the string "hello world" from one place in memory to another through the use of the Raspberry Pi's DMA peripheral.

Run `sudo ./dma-gpio` for an example which toggles a GPIO output pin at 500Hz using DMA. This code (dma-gpio.c) creates a 8ms circular buffer of future output states for all 64 IOs and uses DMA to sequentially copy this buffer into the memory-mapped GPIO registers at a rate of 250,000 frames per second. This allows one to output precise waveforms to any GPIO pin without worrying about Linux task scheduling. The PWM peripheral is used for pacing the DMA transaction, so simultaneous audio output will likely cause errors. Heavy network or USB usage will decrease the timing accuracy for frame rates of 500,000+ fps, due to bus-contention, but even downloading a file at 1MB/sec only has a *very* small impact at 250,000 fps.

Some code, namely for translating virtual addresses to physical ones within dma-example.c, was based on that found in the Raspberry Pi FM Transmitter which I *think* is by either Oliver Mattos or Oskar Weigl, but their website has been down for a while now. Some of the code can still be found here: http://www.raspians.com/turning-the-raspberry-pi-into-an-fm-transmitter/

Problems
======

The virtual->physical mapping function in `dma-example.c` is not cache-coherent. That means that the dma engine might see different data than the cpu. The equivalent functions in `dma-gpio.c` behave correctly, so it is only a matter of porting that code.

The code hasn't been tested extensively on non-Pi v1 (e.g. Pi2, Pi3, Pi Zero). There may be some latent bugs on other hardware versions. Please report any if found.

License
======

I'm putting this code in the public domain. However, the two functions in dma-example.c - `makeVirtPhysPage` and `freeVirtPhysPage` - were based on code found in the FM Transmitter, which was GPL-licensed. If you want to use this code under a non-GPL license, I would recommend replacing those functions with your own code, just to be extra safe. **Disclaimer**: I am not a lawyer.
