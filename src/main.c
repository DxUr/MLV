#include <stdio.h>
#include "extra/esc_code.h"
#include "proc/proc.h"
#include <memory.h>
int main(int argc, char const *argv[])
{
    puts("You are in user queue");
    puts("Q/A:");
    puts("How many proc do u have:");
    int ucount;
    scanf("%d", &ucount);
    
    Proc uprs[ucount];
    memset(uprs, 0, ucount * sizeof(Proc));
    FCFS(uprs, ucount);

    puts("You are in system queue");
    puts("Q/A:");
    puts("How many proc do u have:");
    int scount;
    scanf("%d", &scount);
    
    Proc sprs[scount];
    RR(sprs, scount, 2);

    MLV(sprs, scount, uprs, ucount);

    return 0;
}
