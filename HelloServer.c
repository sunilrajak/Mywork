#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<errno.h>
main()
{
int sock;
unsigned int len;
int cli;
char mesg[]="Welcome to Socket Programming";
struct sockaddr_in server,client;
socket(AF_INET, SOCK_STREAM, 0);
server.sin_family=AF_INET;
server.sin_port=htons(10000);
server.sin_addr.s_addr=INADDR_ANY;
bzero(&server.sin_zero,8);
len=sizeof(struct sockaddr_in);
bind(sock,(struct sockaddr *) &server,len);
listen(sock,5);
while(1)
{

if((cli=accept(sock,(struct sockaddr *)&client,&len==-1)))
{
perror("accept");
exit(-1);
}
send(cli,mesg,strlen(mesg),0);
close(cli);
}
}
