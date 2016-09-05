/*
 * https://github.com/Wallacoloo/Raspberry-Pi-DMA-Example : DMA Raspberry Pi Examples
 * Author: Colin Wallace

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>
*/

/*
 * processor documentation for RPI1 at: http://www.raspberrypi.org/wp-content/uploads/2012/02/BCM2835-ARM-Peripherals.pdf
 * pg 38 for DMA
 */

#pragma once

//-------- physical addresses for the peripherals, as found in the processor documentation:
#if defined(RPI_V1)
#define TIMER_BASE    0x20003000
#define DMA_BASE      0x20007000
#define CLOCK_BASE    0x20101000 // Undocumented. Taken from http://www.scribd.com/doc/127599939/BCM2835-Audio-clocks
#define GPIO_BASE     0x20200000
#define PWM_BASE      0x2020C000
#define GPIO_BASE_BUS 0x7E200000 //this is the physical bus address of the GPIO module. This is only used when other peripherals directly connected to the bus (like DMA) need to read/write the GPIOs
#define PWM_BASE_BUS  0x7E20C000

#elif defined(RPI_V2) || defined(RPI_V3)
// RPI2 and 3 use a different chipset, and the peripheral addresses have changed.
#define TIMER_BASE    0x3F003000
#define DMA_BASE      0x3F007000
#define CLOCK_BASE    0x3F101000 // Undocumented. Extrapolated from RPI_V1 CLOCK_BASE
#define GPIO_BASE     0x3F200000
#define PWM_BASE      0x3F20C000
#define GPIO_BASE_BUS 0x7E200000 //this is the physical bus address of the GPIO module. This is only used when other peripherals directly connected to the bus (like DMA) need to read/write the GPIOs
#define PWM_BASE_BUS  0x7E20C000

#else
#error "Must define either RPI_V1, RPI_V2 or RPI_V3, based on target."
#endif

