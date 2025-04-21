#ifndef IO_H
#define IO_H

#include "typedef.h"

//VGA Text Buffer Const
#define VGA_TEXT_BUFFER 0xB8000

//Colour Constants
#define BLACK         0x0
#define BLUE          0x1
#define GREEN         0x2
#define CYAN          0x3
#define RED           0x4
#define MAGENTA       0x5
#define BROWN         0x6
#define LIGHT_GRAY    0x7
#define DARK_GRAY     0x8
#define LIGHT_BLUE    0x9
#define LIGHT_GREEN   0xA
#define LIGHT_CYAN    0xB
#define LIGHT_RED     0xC
#define LIGHT_MAGENTA 0xD
#define YELLOW        0xE
#define WHITE         0xF


//Frame Buffer Constants
#define FB_COMMAND_PORT 0x3D4
#define FB_DATA_PORT 0x3D5
#define FB_HIGH_BYTE_COMMAND 14
#define FB_LOW_BYTE_COMMAND 15
#define VGA_WIDTH 80
#define VGA_LENGTH 25
#define DEFAULT_TEXT (WHITE << 8)

#define VGA_BUFF ((volatile uint16_t*)VGA_TEXT_BUFFER)


extern void outb(unsigned short port, unsigned char data);
extern uint8_t inb(unsigned short port);


#endif 

