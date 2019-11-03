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
  struct proc_stat s;
  s.pid = 1;
  printf(1, "My first xv6 program %d %d\n",waitx(&i,&i),getpinfo(&s));
  int pid = fork();
  if(pid<0)
  {
    printf(1,"Failed to fork\n");
  }
  else if(pid == 0)
  {
    printf(1,"entered\n");
    long temp = 0;
    int a[50000000];
    a[0]=1;
    for(long i=0;i<300000000;i+=1)
    {
      if(i%50000000 == 0)
        printf(1,"i = %d\n",i);
      temp += a[i%50000000];
    }
    printf(1,"1");
    for(long i=0;i<300000000;i+=1)
    {
      if(i%50000000 == 0)
        printf(1,"i = %d\n",i);
      temp += a[i%50000000];
    }
    printf(1,"2");
    for(long i=0;i<300000000;i+=1)
    {
      if(i%50000000 == 0)
        printf(1,"i = %d\n",i);
      temp += a[i%50000000];
    }
    printf(1,"3");
    for(long i=0;i<300000000;i+=1)
    {
      if(i%50000000 == 0)
        printf(1,"i = %d\n",i);
      temp += a[i%50000000];
    }
    printf(1,"4");
    for(long i=0;i<300000000;i+=1)
    {
      if(i%50000000 == 0)
        printf(1,"i = %d\n",i);
      temp += a[i%50000000];
    }
    printf(1,"5");
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
