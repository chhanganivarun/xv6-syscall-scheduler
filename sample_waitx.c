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
    while(s.runtime < 200)
    {
      if(i%50000000 == 0)
        printf(1,"i = %d\n",i);
      temp += a[i%50000000];
      i++;
      getpinfo(&s);
      printf(1,"runtime %d",s.runtime);  
    }
    temp = temp;
    getpinfo(&s);
    // printf(1,"getpinfo %d\n",s.runtime);
    printf(1,"PID %d num_run %d",s.pid,s.num_run);
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
