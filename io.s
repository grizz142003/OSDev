
global outb

outb:
    mov al, [esp + 8]
    mov dx, [esp + 4]
    out dx, al
    ret


global inb

inb:
    mov dx, [esp + 4]
    in al, dx
    ret

global gdt_flush

gdt_flush:
    mov eax, [esp + 4]
    lgdt [eax]

    ; Load data segments (offsets into GDT)
    mov ax, 0x10   ; Kernel data segment selector (index 2 << 3)
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    ; Far jump to reload code segment
    jmp 0x08:.flush_done  ; Kernel code segment selector (index 1 << 3)
.flush_done:
    ret
    