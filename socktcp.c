#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
void main()
{
        int sock,cli;
        struct sockaddr_in server,client;
        sock=socket(AF_INET,SOCK_STREAM,0);
        unsigned int len;
        char mesg[] = "Welcome to the Socket Programming";
        char buff[50];
        int sent;

        server.sin_family=AF_INET;
        server.sin_port=htons(7899);
        server.sin_addr.s_addr=INADDR_ANY;
        bzero(&server.sin_zero,8);

        len=sizeof(struct sockaddr_in);

        bind(sock, (struct sockaddr *)&server,len);

        listen(sock, 5);

        while(1)
                {

                        cli=accept(sock, (struct sockaddr *)&client,&len);
                        send(cli,mesg,strlen(mesg),0);

                       

                }
close(cli);
}         
