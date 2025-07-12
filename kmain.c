#include "FrameBuff.h"
#include "serial.h"
#include "gdt.h"

void kmain(void){
    gdt_install();

    char message[] = "Gianlucas simple os";
    fb_clear();
    fb_write(message, 20);
    serial_configure_baud_rate(SERIAL_COM1_BASE, 12);
    serial_configure_line(SERIAL_COM1_BASE);
    serial_write(SERIAL_COM1_BASE, message, 20);

    while(1);
}