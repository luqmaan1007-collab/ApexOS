; boot/boot.asm
[ORG 0x7C00]
BITS 16

start:
    cli
    xor ax, ax
    mov ds, ax
    mov ss, ax
    mov sp, 0x7C00
    sti

    ; print message
    mov si, boot_msg
print_loop:
    lodsb
    cmp al, 0
    je done_print
    mov ah, 0x0E
    int 0x10
    jmp print_loop
done_print:

    ; load 10 sectors after bootloader into 0x1000
    mov bx, 0x1000       ; load address
    mov dh, 0            ; head
    mov dl, 0x80         ; drive 0x80
    mov ch, 0            ; cylinder
    mov cl, 2            ; sector 2 (after boot sector)
    mov al, 10           ; number of sectors
load_loop:
    push bx
    mov ah, 0x02         ; BIOS read sectors
    int 0x13
    jc load_error
    add bx, 512
    inc cl
    pop bx
    loop load_loop

    ; jump to kernel
    jmp 0x0000:0x1000

load_error:
    hlt

times 510-($-$$) db 0
dw 0xAA55

boot_msg db "ApexOS Booting...",0
