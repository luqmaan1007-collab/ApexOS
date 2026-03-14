#include "screen.h"   // Needed for print()
#include "memory.h"   // Optional: if you want to allocate space for executables

// Simple executable loader placeholder
void load_executable(const char* path) {
    // In a real OS, you would parse PE/ELF files here
    print("Loading executable: ");
    print((char*)path);
    print("\n");
    
    // Placeholder memory allocation (just for demonstration)
    void* exec_mem = kmalloc(512);
    if (exec_mem) {
        print("Executable memory allocated.\n");
    } else {
        print("Failed to allocate memory for executable.\n");
    }
}
