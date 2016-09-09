#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<errno.h>
#include<pthread.h>
void *whatsapp();
void *chat();
int sock,cli;
struct sockaddr_in server,client;
unsigned int len;
char mesg[]="Welcome to socket programming";
char buff[100];
int portn=7789;
pthread_t thread1,thread2;
void main()
{
       
        pthread_create(&thread1,NULL,whatsapp,NULL);
        pthread_join(whatsapp, NULL);
        pthread_exit(NULL);
 
}
void *whatsapp()
 {       
        if((sock=socket(AF_INET,SOCK_STREAM,0))==-1)
        {
                perror("Socket:");
        }

        server.sin_family=AF_INET;
        server.sin_port=htons(7791);
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
//                                pthread_exit(NULL);
         
                                }
                    }
void *chat(int s)
{
int cli=(int)s;
                                for(;;)
                                {
                                 recv(cli,buff,sizeof(buff),0);
                                 puts(buff);
				continue;
                                // gets(buff);
                                // send(cli,buff,sizeof(buff),0);
                                 }
               
              // pthread_exit(NULL);
}

