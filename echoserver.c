#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<errno.h>
void main()
{
	int sock,cli;
	struct sockaddr_in server,client;
	if((sock=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("Socket:");
	}
        unsigned int len;
	char mesg[] = "Welcome to the Socket Programming";
	char buff[100];
	char buf[100];
	int sent;


	server.sin_family=AF_INET;
	server.sin_port=htons(8585);
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
	
	while(1)
		{
		
			 if((cli=accept(sock, (struct sockaddr *)&client,&len))==-1)
				{
				perror("accept");
				}
				for(;;)
				{
                          	 recv(cli,buff,sizeof(buff),0);
                         	 send(cli,buff,sizeof(buff),0);
				}

                        

		}
		close(cli);
	 }
