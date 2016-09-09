#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
void main()
{
        int sock2;
        struct sockaddr_in server;
        sock2=socket(AF_INET,SOCK_STREAM,0);
        unsigned int len;
        char mesg[] = "Welcome to the Socket Programming";
        char buff[50];

        server.sin_family=AF_INET;
        server.sin_port=htons(9999);
        server.sin_addr.s_addr=INADDR_ANY;

        connect(sock2,(struct sock2*)&server,sizeof(server));
        gets(buff);
        send(sock2,buff,sizeof(buff),0);
        recv(sock2,buff,sizeof(buff),0);
        puts(buff);
        printf("\n");
        close(sock2);
}
