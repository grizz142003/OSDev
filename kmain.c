#include "io.h"


void fb_move_curser(unsigned short pos)
{
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT, pos & 0x00FF);
}
void char_out(char message[], uint8_t color){
    uint16_t* vga = (uint16_t*)VGA_TEXT_BUFFER;

    for (int i = 0; message[i] != '\0'; i++){
        vga[i] = (color << 8) | message[i];
    }
}


void kmain(void){
    
    fb_move_curser(11);

    char message[] = "Hello World!";
    uint8_t color = (BLACK << 4) | WHITE;

    char_out(message, color);

    char mess2[] = "World";
    char_out(mess2, color);
    
    while(1);
}