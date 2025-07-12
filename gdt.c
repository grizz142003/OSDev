#include "gdt.h"

#define GDT_ENTRIES 5
struct GDTEntry gdt[GDT_ENTRIES];
struct GDTPointer gdt_ptr;

void set_gdt_entry(int num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran) {
    gdt[num].base_low    = base & 0xFFFF;
    gdt[num].base_middle = (base >> 16) & 0xFF;
    gdt[num].base_high   = (base >> 24) & 0xFF;

    gdt[num].limit_low   = limit & 0xFFFF;
    gdt[num].granularity = ((limit >> 16) & 0x0F) | (gran & 0xF0);

    gdt[num].access = access;
}

void gdt_install() {
    gdt_ptr.limit = (sizeof(struct GDTEntry) * GDT_ENTRIES) - 1;
    gdt_ptr.base = (uint32_t)&gdt;

    // Null descriptor
    set_gdt_entry(0, 0, 0, 0, 0);

    // Kernel code segment
    set_gdt_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);

    // Kernel data segment
    set_gdt_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF);

    // User code segment
    set_gdt_entry(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);

    // User data segment
    set_gdt_entry(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);

    gdt_flush((uint32_t)&gdt_ptr);
}
