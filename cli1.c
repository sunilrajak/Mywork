#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<netdb.h>
void main(int argc,char** argv)
{
	int sock2;
        struct sockaddr_in server;
       // struct hostent *lh = gethostbyname(argv[1]);
        sock2=socket(AF_INET,SOCK_STREAM,0);
       // printf("ye %d",sock2);
        unsigned int len;
	int fd;
	fd_set clientfds,testfds;
       // char mesg[] = "Welcome to the Socket Programming";
        char buff[100];
        char buf[100];
        server.sin_family=AF_INET;
        server.sin_port=htons(8001);
        inet_pton(AF_INET,argv[1],&server.sin_addr);
        printf("Please Enter your Name");
        gets(buf);

	int d=(connect(sock2,(struct sock2*)&server,sizeof(server)));
         // printf("This is connect %d\n",d);
              if(d==-1)
		{
                perror("connect");
		}
    
           send(sock2,buf,sizeof(buf),0);
       // printf("Hehe check %d",getpid());
         FD_ZERO(&clientfds);
	 FD_SET(sock2,&clientfds);
	 FD_SET(0,&clientfds);

        for(;;)
	{
	testfds=clientfds;
	select(FD_SETSIZE,&testfds,NULL,NULL,NULL);

	for(fd=0;fd<FD_SETSIZE;fd++)
         {
         if(FD_ISSET(fd,&testfds))
         {
	  if(fd==sock2)
            {
             recv(sock2,buff,sizeof(buff),0);
	     puts(buff);
	    }
       else if(fd==0)
	{
            gets(buff)!=NULL;
	
	send(sock2,buff,sizeof(buff),0);
        gets(buff);
        send(sock2,buff,sizeof(buff),0);
	
       //for(;;)
	// {
        // if(recv(sock2,buff,sizeof(buff),0)!=0)
	// {
  	// printf("This is from Server \n");
        // puts(buff);
 	// break;
//	printf("\n");
	}
	}


}
}
}
