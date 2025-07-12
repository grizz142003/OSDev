// gdt.h
#include "io.h"

#ifndef GDT_H
#define GDT_H

extern void gdt_flush(uint32_t); 

struct GDTEntry {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t  base_middle;
    uint8_t  access;
    uint8_t  granularity;
    uint8_t  base_high;
} __attribute__((packed));

struct GDTPointer {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));
void set_gdt_entry(int num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran);
void gdt_install(void);

#endif // GDT_H
