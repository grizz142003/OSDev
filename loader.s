
global loader

BITS 32

MAGIC_NUMBER equ 0x1BADB002
FLAGS equ 0x0
CHECKSUM equ -MAGIC_NUMBER

section .text:
align 4
    dd MAGIC_NUMBER
    dd FLAGS
    dd CHECKSUM

loader:
    
    ;extern gdt
    ;call gdt
     
    mov esp, kernel_stack + KERNEL_STACK_SIZE


    extern kmain
    call kmain

    
.loop:
    jmp $


section .bss
align 4
KERNEL_STACK_SIZE equ 4096
kernel_stack:
    resb KERNEL_STACK_SIZE


