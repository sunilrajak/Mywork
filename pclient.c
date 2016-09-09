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
        int sock3;
        struct sockaddr_in server;
        sock3=socket(AF_INET,SOCK_STREAM,0);
        unsigned int len;
       // char mesg[] = "Welcome to the Socket Programming";
        char buff[100];
        char buf[100]="linus";
        server.sin_family=AF_INET;
        server.sin_port=htons(8001);
        server.sin_addr.s_addr=INADDR_ANY;


        if((connect(sock3,(struct sock3*)&server,sizeof(server)))==-1)
                {
                perror("connect");
                }
        send(sock3,buf,sizeof(buf),0);
     
        for(;;)
        {
       if(gets(buff)!=NULL)
	{
	send(sock3,buff,sizeof(buff),0);
 	gets(buff);
	send(sock3,buff,sizeof(buff),0);
	}
        for(;;)
	{
        if(recv(sock3,buff,sizeof(buff),0)!=0)
        {
        printf("This is from ServerSunil \n");
        puts(buff);
	break;
        }
	}
       
       // printf("\n");
        //}



}
}
