#include "gdt.h"

struct gdt_entry gdt[3];

void load_gdt(struct gdt *gdt_ptr){
    asm volatile("lgdt (%0)" : : "r"(gdt_ptr));
}

void load_segments(){
    unsigned short code_selector = CODE_SEGMENT;
    unsigned short data_selector = DATA_SEGMENT;

    asm volatile(
        "mov %0, %%ax;"
        "mov %%ax. %%ds;"
        "mov %%ax. %%es;"
        "mov %%ax. %%fs;"
        "mov %%ax. %%gs;"
        "mov %%ax. %%ss;"
        "mov %1. %%ax;"
        "jmp %%ax, $1f;"
        "1:"
        :
        : "r"(data_selector), "r"(code_selector)
        : "%ax");
}

void init_gdt(){
    gdt[0].base_low = 0;
    gdt[0].base_high = 0;
    gdt[0].limit_low = 0;
    gdt[0].granularity = 0;

    gdt[1].base_low = 0;
    gdt[1].base_high = 0;
    gdt[1].limit_low = 0xFFFF;
    gdt[1].granularity = 0x9A;
    gdt[1].granularity |= 0xCF000000;   

    gdt[2].base_low = 0;
    gdt[2].base_high = 0;
    gdt[2].limit_low = 0xFFFF;
    gdt[2].granularity = 0x92;
    gdt[2].granularity |= 0xCF000000;
    
    struct gdt gdt_ptr;
    gdt_ptr.adress = (unsigned int)&gdt;
    gdt_ptr.size = sizeof(gdt) - 1;
}