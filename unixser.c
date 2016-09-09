#include<stdio.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<stdlib.h>
#include<errno.h>
char *socket_path;
void main(int argc,char *argv[])
{
struct sockaddr_un addr;
char buff[100];
int sockfd,cl;
socket_path=argv[1];
if((sockfd=socket(AF_UNIX,SOCK_STREAM,0))==-1)
	{ 	
	perror("Socket:");
	}	
addr.sun_family=AF_UNIX;
strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);
unlink(socket_path);

if((bind(sockfd,(struct sockaddr*)&addr,sizeof(addr)))==-1)
	{
		perror("BIND:");
	}
if((listen(sockfd,5)==-1))
	{
           	perror("listten:");
	}	
while(1)
	{
		if((cl=accept(sockfd,NULL,NULL))==-1)
			{
				perror("Accept:");
			}
			while(1)
				{
					read(cl,buff,sizeof(buff),0);
					puts(buff);
					gets(buff);
					write(cl,buff,sizeof(buff),0);
				}
		close(cl);
	}
}
