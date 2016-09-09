#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#define BufferSize 10

void *Producer();
void *Consumer();

int BufferIndex=0;
char BUFFER[10];

int s=1;
int e=10;
int f=0;

pthread_cond_t Buffer_Not_Full=PTHREAD_COND_INITIALIZER;
pthread_cond_t Buffer_Not_Empty=PTHREAD_COND_INITIALIZER;
pthread_mutex_t mVar=PTHREAD_MUTEX_INITIALIZER;

int main()
{
pthread_t ptid,ctid;

printf("Hello worl");
pthread_create(&ptid,NULL,Producer,NULL);
pthread_create(&ctid,NULL,Consumer,NULL);

return 0;

}

void *Producer()
{

for(;;)
	{
         wait(e);
         wait(s);
         BUFFER[BufferIndex++]='@';
         signal(s);
	 signal(f);
	}
}

void *Consumer()
{
for(;;)
	{
		wait(f);
		wait(s);
		BUFFER[BufferIndex--];
		signal(s);
		signal(e);

	}
}
   
