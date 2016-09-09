#include<sys/socket.h>
#include<sys/un.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
char *socket_path;
void main(int argc,char *argv[])
{
struct sockaddr_un addr;
char buff[100];
int sockfd,rc;
socket_path=argv[1];
if((sockfd=socket(AF_UNIX,SOCK_STREAM,0))==-1)
	{
		perror("Socket");
	}
addr.sun_family=AF_UNIX;
strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);
if((connect(sockfd,(struct sockaddr*)&addr,sizeof(addr)))==-1)
	{
		perror("Connection:");
	}
while(1)
	{
		rc=read(STDIN_FILENO,buff,sizeof(buff));
		write(sockfd,buff,rc);
		printf("This is from Server \n");
		puts(buff);
		printf("\n");
	}
}
