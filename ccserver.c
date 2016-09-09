#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<errno.h>
#include<pthread.h>
#include<netdb.h>


void *whatsapp();
void *chat();
void *Producer();
void *Consumer();
int sock,cli;

pthread_cond_t Buffer_Not_Full=PTHREAD_COND_INITIALIZER;
pthread_cond_t Buffer_Not_Empty=PTHREAD_COND_INITIALIZER;
pthread_mutex_t mVar=PTHREAD_MUTEX_INITIALIZER;

struct sockaddr_in server,client;
unsigned int len;
char mesg[]="Welcome to socket programming";
char buff[100];
int portn=7793;
pthread_t thread1,thread2;
pthread_t sunil,rajak;
void main()
{
        long t;        

        pthread_create(&thread1,NULL,whatsapp,(void *)t);
        pthread_join(thread1, NULL);
        pthread_exit(NULL);
 
}
void *whatsapp(void *threadid)
 {       
        long tid;
        tid = (long)threadid;
        printf("Thread id is %ld\n",tid);
        if((sock=socket(AF_INET,SOCK_STREAM,0))==-1)
        {
                perror("Socket:");
        }

        server.sin_family=AF_INET;
        server.sin_port=htons(7796);
        server.sin_addr.s_addr=INADDR_ANY;
        bzero(&server.sin_zero,8);

        len=sizeof(struct sockaddr_in);

        if((bind(sock, (struct sockaddr *)&server,len))==-1)
        {
                perror("bind");
        }

        if((listen(sock, 5))==-1)
        {
        perror("listem");
        exit(-1);
        }

       
                while(1){

                         if((cli=accept(sock, (struct sockaddr *)&client,&len))==-1)
                                {
                                perror("accept");
                                }
                                pthread_create(&thread2,NULL,chat,cli);
                               // printf("\ncli ka %d",cli);
                                
         
                                }
                    }
void *chat(int s)
{
int cli=(int)s;              
                              for(;;)
                              {
                              pthread_create(&sunil,NULL,Producer,cli);
                              pthread_join(sunil,NULL);
                              puts(buff);
			      pthread_create(&rajak,NULL,Consumer,cli);
			     
                              pthread_join(rajak,NULL);
                              
                           
                              }
			     	
}

void *Producer(int p)
           {
            int cli=(int)p;
	                       pthread_mutex_lock(&mVar);
                               // for(;;)
                                {
                            
                                 recv(cli,buff,sizeof(buff),0);
                                
                                // pthread_join(rajak,NULL);
                                }
                                pthread_mutex_unlock(&mVar);
            }
        
void *Consumer(int c)
            {
             int cli = (int)c; 
                                pthread_mutex_lock(&mVar);
                                // for(;;)
                                 {
                              if(cli==5)
                                 { 
                                 send(cli,buff,sizeof(buff),0);
                                 }
                                // continue;
                                 }
                                 pthread_mutex_unlock(&mVar);
             
}

