#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<errno.h>
#include<pthread.h>
#include<netdb.h>

void whatsapp();
void *chat();
void *Producer();
void *Consumer();
int j=0;
int k=0;
int l=0;
int m=0;
int sock,cli;
fd_set readfds;
struct sockaddr_in server,client;
unsigned int len;
char buff[100];
char buf[100];
char bufs[100];
char idea[100]="DATA";
pthread_t thread,sunil,rajak;

struct clientdata
{
	char name[30];
	int sockfd;
};

void main()
{
whatsapp();
}
void whatsapp()
{
int n;
struct clientdata record[100];
if((sock=socket(AF_INET,SOCK_STREAM,0))==-1)
    {
	perror("Socket");
    }
    server.sin_family=AF_INET;
    server.sin_port=htons(8001);
    server.sin_addr.s_addr=INADDR_ANY;
    
len=sizeof(struct sockaddr_in);

if((bind(sock, (struct sockaddr *)&server,len))==-1)
   { 
	perror("bind");
   }

if((listen(sock, 5))==-1)
  {
   perror("listen");
  }
FD_ZERO(server,1);
FD_SET(&readfds);
FD_SET(server,&readfds);
FD_SET(0,&readfds);
while(1)
    {
     testfds=readfds;
     select(FD_SETSIZE,&testfds,NULL,NULL,NULL);

      for(fd=0;fd<FD_SETSIZE;fd++)
	{
         if(FD_ISSET(fd,&testfds))
           {
         if(fd==server)
	 {
         if((cli=accept(sock, (struct sockaddr *)&client,&len))==-1)
         {
         perror("accept");
         }
         
          recv(cli,buf,sizeof(buf),0);
         
          
          strcpy(record[j++].name,buf);
          record[k++].sockfd=cli;
          
         // pthread_create(&thread,NULL,chat,cli);


         
           printf("This is Call from %s \n",record[l++].name);
           printf("This is socket fd %d \n",record[m++].sockfd);
        // puts(buf);
          
        pthread_create(&thread,NULL,chat,cli);
         // chat();
}     
}
void *chat(int s)
   {
   int cli=(int)s;
     for(;;)
         {
           pthread_create(&sunil,NULL,Producer,cli);
          // Producer();
            pthread_join(sunil,NULL);
           puts(buff);
         // pthread_create(&rajak,NULL,Consumer,cli);
         // pthread_join(rajak,NULL);
         }
     }

void *Producer(int p)
//void Producer()
   {
   int cli=(int)p;
           {
           recv(cli,bufs,sizeof(bufs),0);
           recv(cli,buff,sizeof(buff),0);
           }
           cli=atoi(bufs);
          // cli++;
          // puts(cli);
           //send(cli,buff,sizeof(buff),0);
           pthread_create(&rajak,NULL,Consumer,cli);
           pthread_join(rajak,NULL);
   }

void *Consumer(int c)
   {
     int cli = (int)c;
          {
		send(cli,buff,sizeof(buff),0);
          }
   }
