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
            getpinfo(&s);
            printf(1,"Child created %d %d\n",s.pid,getpid());
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
