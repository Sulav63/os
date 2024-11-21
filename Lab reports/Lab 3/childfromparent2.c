#include <stdio.h>
#include <unistd.h> //contains fork prototype
int main()
{
int pid,pid2;
pid = fork();
if (pid == 0)
{
printf("\nChild Process id : %d",getpid());
printf("\nChild Process with parent id : %d \n",getppid());
}
pid2=fork();
if(pid2==0){
printf("\nChild Process id : %d",getpid());
printf("\nChild Process with parent id : %d \n",getppid());
}
return 0;
}

