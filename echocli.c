#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
void main()
{
        int sock2;
        struct sockaddr_in server;
        sock2=socket(AF_INET,SOCK_STREAM,0);
        unsigned int len;
       // char mesg[] = "Welcome to the Socket Programming";
        char buff[100];
        char buf[100];
        server.sin_family=AF_INET;
        server.sin_port=htons(8585);
        server.sin_addr.s_addr=INADDR_ANY;


        if((connect(sock2,(struct sock2*)&server,sizeof(server)))==-1)
                {
                perror("connect");
                }
        for(;;)
        {
        gets(buff);
        send(sock2,buff,sizeof(buff),0);
        recv(sock2,buff,sizeof(buff),0);
       // printf("This is from Server \n");
        puts(buff);
//      printf("\n");
        }

        close(sock2);

}

