typedef struct {
    int pid;
    void (*entry)();
    int state;
} Process;

Process proc_list[8];
int proc_count=0;

void init_processes(){
    proc_count=0;
}

void add_process(void (*entry)()){
    proc_list[proc_count].pid=proc_count;
    proc_list[proc_count].entry=entry;
    proc_list[proc_count].state=1;
    proc_count++;
}
