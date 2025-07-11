#include "serial.h"

void serial_configure_baud_rate(unsigned short com, unsigned short divisor){
    outb(SERIAL_LINE_COMMAND_PORT(com), SERIAL_LINE_ENABLE_DLAB);
    outb(SERIAL_DATA_PORT(com), (divisor >> 8) & 0x00FF);
    outb(SERIAL_DATA_PORT(com), divisor & 0x00FF);
}

void serial_configure_line(unsigned short com){
    outb(SERIAL_LINE_COMMAND_PORT(com), 0x03);
    //configures the line for 8 bits and 1 stop bit
    //can be changed to different configurations if neccessary
}

int serial_is_transmit_fifo_empty(unsigned int com){
    return inb(SERIAL_LINE_STATUS_PORT(com)) & 0x20;
}
void serial_write_byte(unsigned short com, const char out){
    while(!serial_is_transmit_fifo_empty(com));
    outb(SERIAL_DATA_PORT(com), out);
}
void serial_write(unsigned short com, char *output, uint8_t len){
    for(uint8_t i = 0; i < len; i++){
        serial_write_byte(com, output[i]);
    }
}