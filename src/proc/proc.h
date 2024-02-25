#pragma once

#include <stdint.h>

typedef enum {
    SP = 1,
    UP = 2
} queue_e;



typedef struct {
    uint16_t id;
    uint32_t brust_time;
    uint32_t wait_time;
    uint32_t turn_around_time;
    uint32_t arrival_time;
    uint32_t comp_time;
    queue_e queue;
} Proc;




void FCFS(Proc *p_prs, int p_count);
void RR(Proc *p_prs, int p_count, uint32_t p_slice_time);
void MLV(Proc *p_sprs, int p_scount, Proc *p_uprs, int p_ucount);






