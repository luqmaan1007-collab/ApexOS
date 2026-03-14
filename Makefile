all:
    nasm boot/boot.asm -f bin -o boot.bin
    gcc -ffreestanding -m32 -c kernel/*.c -o kernel.o
    ld -m elf_i386 -T linker.ld kernel.o -o kernel.bin
    cat boot.bin kernel.bin > apexos.img
    qemu-system-x86_64 apexos.img
