#include "screen.h"
#include "shell.h"

void kernel_main() {
    clear_screen();
    print("ApexOS Booted!\n");
    shell(); // jump to shell
}
