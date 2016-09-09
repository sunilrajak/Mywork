#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<pthread.h>
void *func(void *);
int sock2;
char buff[100];
int i=0;
void main()
{
        struct sockaddr_in server;
        sock2=socket(AF_INET,SOCK_STREAM,0);
        unsigned int len;
	pthread_t threads[5];
        int t;
	int rc;
       // char mesg[] = "Welcome to the Socket Programming";
        //char buff[100];
        char buf[100];
        server.sin_family=AF_INET;
        server.sin_port=htons(8111);
        server.sin_addr.s_addr=INADDR_ANY;
  
       
        if((connect(sock2,(struct sock2*)&server,sizeof(server)))==-1)
                {
                perror("connect");
                }
        for(t=0;t<5;t++)
              {
                    printf("In main: creating thread %ld\n",t);
		    rc = pthread_create(&threads[t],NULL,func,(void *)t);
		    if(rc)
                        {
                         printf("Error; pthread_cread() is %d\n",rc);
                         exit(-1);
                        }
              }
     pthread_exit(NULL);

}
void *func(void *threadid)
  {     
        long tid;
	tid=(long)threadid;
        for(i=0;i<=tid;i++)
        {
        gets(buff);
        send(sock2,buff,sizeof(buff),0);
        recv(sock2,buff,sizeof(buff),0);
        printf("This is from Server \n");
        puts(buff);
        printf("\n");
        }
    printf("Hello world! It's me,thread # %ld!\n",tid);
    pthread_exit(NULL);
 

        close(sock2);

 }

