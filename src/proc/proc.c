#include "proc/proc.h"
#include <stdio.h>
#include <stdbool.h>


void FCFS(Proc *p_prs, int p_count) {
    for (int i = 0; i < p_count; ++i) {
        p_prs[i].queue = UP;
        puts("Enter the process id:");
        scanf("%d", &p_prs[i].id);
        puts("Enter the process burst time:");
        scanf("%d", &p_prs[i].brust_time);
        puts("Enter the process arrival time:");
        scanf("%d", &p_prs[i].arrival_time);
        p_prs[i].wait_time = i == 0 ? 0 : (p_prs[i-1].wait_time + p_prs[i-1].brust_time);
        p_prs[i].turn_around_time = p_prs[i].brust_time + p_prs[i].wait_time;
    }
    
}


void RR(Proc *p_prs, int p_count, uint32_t p_slice_time) {
    for (int i = 0; i < p_count; i++) {
        p_prs[i].queue = UP;
        puts("Enter the process id:");
        scanf("%d", &p_prs[i].id);
        puts("Enter the process burst time:");
        scanf("%d", &p_prs[i].brust_time);
        p_prs[i].comp_time = p_prs[i].brust_time;
        puts("Enter the process arrival time:");
        scanf("%d", &p_prs[i].arrival_time);
    }

    for (int i = 0; i < p_count; i++) {
        uint32_t comp_time = 0;
        uint32_t tmp_time[p_count];

        for (int j = 0; j < p_count; j++)
            tmp_time[j] = p_prs[j].brust_time;
        

        for (int k = 0; tmp_time[i] > 0; k++) {
            comp_time += tmp_time[k] < p_slice_time ? tmp_time[k] : p_slice_time;
            tmp_time[k] -= tmp_time[k] < p_slice_time ? tmp_time[k] : p_slice_time;
            if (k+1 >= p_count)
                k = -1;
        }
        p_prs[i].comp_time = comp_time;
        p_prs[i].turn_around_time = comp_time - p_prs[i].arrival_time;
        p_prs[i].wait_time = p_prs[i].turn_around_time - p_prs[i] .brust_time;
    }
    
    
}


void MLV(Proc *p_sprs, int p_scount, Proc *p_uprs, int p_ucount, uint32_t p_slice_time) {
    uint32_t stmp_time[p_scount];
    uint32_t utmp_time[p_ucount];

    for (size_t i = 0; i < p_scount; i++)
        stmp_time[i] = p_sprs[i].brust_time;
    
    for (size_t i = 0; i < p_ucount; i++)
        utmp_time[i] = p_uprs[i].brust_time;
    

    for (size_t t = 0;; t++) {
        bool fin = false;
        for (int i = 0; i < p_scount; i++) {
            if (p_sprs[i].arrival_time <= t)
                if (stmp_time[i] > 0) {
                    stmp_time[i]--;
                    fin = true;
                }
        }
        if (fin) continue;
        
    }
    





}