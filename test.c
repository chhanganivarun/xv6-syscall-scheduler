#include "types.h"
#include "stat.h"
#include "user.h"
#include "proc_stat.h"

int
main(int argc, char *argv[])
{
    // Example Program for waitx.
    // Run test & followed be test & before the first process finishes
    int n=10;
    if(argc>1)
    {
        n = atoi(argv[1]);
    }
    #ifdef PBS
    int pri[n];
    for(int i=0;i<n;i++)
        pri[i]=60;

    for(int i=2;argc>i+1;i+=2)
    {
        if(atoi(argv[i])>0 && atoi(argv[i])<=n)
        {
            pri[atoi(argv[i])-1] = atoi(argv[i+1]);
        }
    }
    #endif

    struct proc_stat s;
    for(int a0=0;a0<n;a0++)
    {
        int pid = fork();
        if(pid<0)
        {
            printf(1,"Failed to fork\n");
        }
        else if(pid == 0)
        {
            #ifdef PBS
            if(pri[a0]!=60)
                set_priority(pri[a0]);
            #endif
            getpinfo(&s);
            
            printf(1,"Child created %d %d \n",s.pid,s.current_queue);
            long temp = 0;
            for(int j=0;j<2;j++)
            {
                for(long i=0;i<1400000000;i+=1)
                {
                    if(i%50000000 == 0)
                        printf(1,"%d j= %d i = %d\n",s.pid,j,i);
                    temp = temp + 3.14*89.64;
                }
            }
            exit();
        }
    }
    int wtime,rtime;
    waitx(&wtime,&rtime);
    // free(s);
    exit();
}
