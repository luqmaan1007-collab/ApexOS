#ifndef PROCESS_H
#define PROCESS_H

typedef struct {
    int pid;
    void (*entry)();
    int state;
} Process;

void init_processes(void);
void add_process(void (*entry)());

#endif
