#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<netdb.h>
void main()
{
	int sock2;
        struct sockaddr_in server;
        struct hostent *lh = gethostbyname("localhost");
        sock2=socket(AF_INET,SOCK_STREAM,0);
       // printf("ye %d",sock2);
        unsigned int len;
	int fd;
        fd_set client_sockfd;
       // char mesg[] = "Welcome to the Socket Programming";
        char buff[100];
        char buf[100]="Sunil";
        server.sin_family=AF_INET;
        server.sin_port=htons(8001);
        server.sin_addr.s_addr=INADDR_ANY;
        

	int d=(connect(sock2,(struct sock2*)&server,sizeof(server)));
         // printf("This is connect %d\n",d);
              if(d==-1)
		{
                perror("connect");
		}
    
           send(sock2,buf,sizeof(buf),0);
       // printf("Hehe check %d",getpid());
         
        for(;;)
	{
	if(gets(buff)!=NULL)
	{
	send(sock2,buff,sizeof(buff),0);
        gets(buff);
        send(sock2,buff,sizeof(buff),0);
	}
       for(;;)
	 {
         if(recv(sock2,buff,sizeof(buff),0)!=0)
	 {
  	 printf("This is from Server \n");
         puts(buff);
 	 break;
//	printf("\n");
	}
	}


}
}

