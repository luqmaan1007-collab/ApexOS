unsigned int mem_top = 0x100000;

void* kmalloc(unsigned int size){
    void* ptr = (void*)mem_top;
    mem_top += size;
    return ptr;
}

void init_memory(){
    mem_top = 0x100000;
}
