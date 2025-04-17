# ILI9488 Driver for STM32

A driver for the ILI9488 LCD controller which uses the STM32 HAL libraries over SPI. This driver was written and tested on a STM32L476xx development board.

## Installation
This repo contains the driver itself, as well as a couple of sample bitmaps, and a font file. Copy the *.c*, and *.h* files to their respective directories in your project. 

* A sample **main.c** file is included to demonstrate initialising the LCD and basic functions.
* **img2hex.py** is a simple script that will convert a *.png* file to HEX values represented as ASCII which can then be copied in to your project as an array. See the *bitmaps.h* file for an example.
* **bitmaps.h** contains a couple of sample images but is not required by the driver.
* **font.h** IS required by the driver.
<br />

* The SPI port should be initialised by your *main.c* file, and declared as ```extern SPI_HandleTypeDef hspix``` in the *ILI9488.h* file.
* Change the **CS**, **D/C**, and **RES** pins in the *ILI9488.h* file to suit your project.
* Serial (SPI), or parallel communication can be selected with a flag in the *ILI9488.h* file. (TODO: Parallel comms currently don't work)
* Portrait or Landscape orientation can be selected with a flag in the *ILI9488.h* file.
* This implementation uses a two partial framebuffers and DMA transfers. Change the size of the buffer in *ILI9488.c* to suit your requirements.

## TODO
* Currently the project only writes in serial (SPI). Eventually you will be able to select either serial or parallel communication.
* Images which overlap the edge of the display become distorted (the memory location wraps around). Include a check that the image isn't outside the display area.