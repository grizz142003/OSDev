
global outb

outb:
    mov al, [esp + 8]
    mov dx, [esp + 4]
    out dx, al
    ret


global inb

inb:
    and eax, 0
    mov dx, [esp + 4]
    in al, dx
    ret
    