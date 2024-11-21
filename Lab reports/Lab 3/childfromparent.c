#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
// make two process which run same
// program after this instruction
if(fork()==0){
printf("I am a child.\n");
}
else {
printf("I am the parent.\n");
}
printf("Hello!\n");
return 0;
}

