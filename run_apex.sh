#!/usr/bin/env bash

set -e

# Directories
BOOT_DIR="boot"
KERNEL_DIR="kernel"
BUILD_DIR="$KERNEL_DIR/build"
IMG="apexos.img"

echo "[*] Creating build directory..."
mkdir -p "$BUILD_DIR"

echo "[*] Assembling bootloader..."
nasm "$BOOT_DIR/boot.asm" -f bin -o "$BUILD_DIR/boot.bin"

echo "[*] Compiling kernel C files..."
for f in "$KERNEL_DIR"/*.c; do
    fname=$(basename "$f" .c)
    clang -ffreestanding -target i386 -I"$KERNEL_DIR" -c "$f" -o "$BUILD_DIR/$fname.o"
done

echo "[*] Linking kernel to flat binary..."
lld -flavor gnu -m elf_i386 -T linker.ld --oformat binary \
"$BUILD_DIR"/*.o \
-o "$BUILD_DIR/kernel.bin"

echo "[*] Combining bootloader + kernel..."
cat "$BUILD_DIR/boot.bin" "$BUILD_DIR/kernel.bin" > "$IMG"

echo "[*] Starting QEMU with VNC on 127.0.0.1:5900..."
qemu-system-i386 -drive format=raw,file="$IMG" -vnc :0
