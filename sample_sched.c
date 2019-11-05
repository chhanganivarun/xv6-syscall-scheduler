#include "types.h"
#include "stat.h"
#include "user.h"
#include "proc_stat.h"

int
main(void)
{
  // Example Program for waitx.
  // Run test & followed be test & before the first process finishes
  int i=3;
  printf(1, "My first xv6 program %d\n",waitx(&i,&i));
  int pid = fork();
  if(pid<0)
  {
    printf(1,"Failed to fork\n");
  }
  else if(pid == 0)
  {
    printf(1,"entered\n");
    struct proc_stat s;
    getpinfo(&s);
    long temp = 0;
    int a[50000000];
    a[0]=1;
    long i = 0;
    for(int j=0;j<3;j++)
    {
      for(i=0;i<1400000000;i++)
      {
        if(i%50000000 == 0)
          printf(1,"pid %d j = %d i = %d\n",s.pid,j,i);
        temp += a[i%50000000];
      }
    }
    temp = temp;
    exit();
  }
  else
  {
    printf(1,"%d\n",pid);
    int wtime,rtime;
    int ret = waitx(&wtime,&rtime);
    printf(1,"Waitx: %d wtime %d rtime %d\n",ret,wtime,rtime);
  }
  
  // free(s);
  exit();
}
