#include "io.h"
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

//void fb_move_curser(unsigned short pos);

void kmain(void){
    

    char message[] = "Hello World!";
    volatile uint16_t* vga = (uint16_t*)VGA_TEXT_BUFFER;



    uint8_t color = (LIGHT_RED << 4) | WHITE;

    for (int i = 0; message[i] != '\0'; i++){
        vga[i] = (color << 8) | message[i];
    }

    
    while(1);
}

/*void fb_move_curser(unsigned short pos){
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT, pos & 0x00FF);
}
    */
