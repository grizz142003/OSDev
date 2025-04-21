#include "FrameBuff.h"

static uint16_t get_curser(void){
    uint16_t pos;
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    pos = ((uint16_t)inb(FB_DATA_PORT)) << 8;
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    pos |= (uint16_t)inb(FB_DATA_PORT);
    return pos;
}

uint16_t fb_get_curser(void){
    return get_curser();
}

static void set_curser(uint16_t pos){
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT, pos >> 8);
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT, pos & 0xFF);
}

void fb_move_curser(uint16_t pos){
    set_curser(pos);
}

static void scroll(void){
    for (int row = 0; row < VGA_LENGTH - 1; row++){
        for (int col = 0; col < VGA_WIDTH; col++){
            VGA_BUFF[row * VGA_WIDTH + col] = VGA_BUFF[(row + 1)* VGA_WIDTH + col];
        }
    }
    uint16_t blank = DEFAULT_TEXT | ' ';
    for (int col = 0; col < VGA_WIDTH; col++){
        VGA_BUFF[(VGA_LENGTH - 1) * VGA_WIDTH + col] = blank;
    }
}

void fb_clear(void){
    
}