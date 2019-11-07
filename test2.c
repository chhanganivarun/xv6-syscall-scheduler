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
            
            // printf(1,"Child created %d %d \n",s.pid,s.current_queue);
            long temp = 0;
            for(int j=0;j<1;j++)
            {
                for(long i=0;i<140000000;i+=1)
                {
                    // printf(1,"");
                    temp = temp + 3.14*89.64;
                }
            }
            temp = temp;
            printf(1,"End %d\n",s.pid);
            getpinfo(&s);
            
            exit();
        }
    }
    int wtime,rtime;
    for(int i=0;i<n;i++)
    {
        waitx(&wtime,&rtime);
        printf(1,"a[i][%d]=%d\n",i,wtime+rtime);
    }
    
    // free(s);
    exit();
}
