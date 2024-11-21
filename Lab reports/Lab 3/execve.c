#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main() {
char *temp[] = {NULL,"hello","world",NULL};
temp[0]="basic";
if(fork()==0){
printf("I am a child process.\n");
printf("My id is: %d\n",getpid());
printf("My parent is: %d\n",getppid());
printf("I am going to execute a c program\n");
execve("basic",temp,NULL);
}
else{
printf("The id of current process is %d\n",getpid());
}
return 0;
}

