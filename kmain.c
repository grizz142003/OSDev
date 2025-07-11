#include "FrameBuff.h"
#include "serial.h"
/*void fb_move_curser(unsigned short pos)
{
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT, pos & 0x00FF);
}
    */

void kmain(void){
    char message[] = "Gianlucas simple os";
    fb_clear();
    fb_write(message, 20);
    serial_configure_baud_rate(SERIAL_COM1_BASE, 12);
    serial_configure_line(SERIAL_COM1_BASE);
    serial_write(SERIAL_COM1_BASE, message, 20);

    while(1);
}