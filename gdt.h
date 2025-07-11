#ifndef gdt_h
#define gdt_h

#define CODE_SEGMENT 0x08
#define DATA_SEGMENT 0x10

struct gdt{
    unsigned int adress;
    unsigned short size;
}__attribute__((packed));

struct gdt_entry{
    unsigned int base_low;
    unsigned int base_high;
    unsigned int limit_low;
    unsigned int granularity;
};

void load_gdt(struct gdt *gdt_ptr);
void load_segments();
void init_gdt();


#endif