//basic creation os thread
#include<stdio.h>
#include<pthread.h>
#include<time.h>
void * show(void * u){
printf("New thread\n");
}
int main(){
pthread_t tid;
time_t t;
time(&t);
printf("\nThis program has been writeen at (date and time): %s", ctime(&t));
pthread_create(&tid,NULL,&show,NULL);
printf("Main thread\n");
pthread_join(tid,NULL);
return 0;
}

// gcc try3.c -o try3 -pthread
