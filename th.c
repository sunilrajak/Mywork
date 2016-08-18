#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

pthread_t tid[2];
int counter;

void* task(void *arg[])
{
  unsigned long i=0;
counter++;
printf("\njob %d started\n",counter);

for(i=0;i<(0xFFFFFFFF);i++);
printf("\n job %d finished\n",counter);
return NULL;
}

int main(void)
{
int i=0;
int err;
while(i<2)
{
err=pthread_create(&(tid[i]),NULL,&task,NULL);
if(err!=0)
printf("\nCan't create thread:[%s]",strerror(err));
i++;
}
pthread_join(tid[0],NULL);
pthread_join(tid[1],NULL);
return 0;
}
