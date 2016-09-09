#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
void main()
{
int udpsock;
char buff[100];
struct sockaddr_in server,client;
struct sockaddr_storage s;
int l;

udpsock=socket(PF_INET,SOCK_DGRAM,0);
//LOG_PRINT("Socket Created");
server.sin_family=PF_INET;
server.sin_port=htons(8888);
server.sin_addr.s_addr=inet_addr("127.0.0.1");

bind(udpsock,(struct sockaddr *) &server,sizeof(server));
l=sizeof(s);
while(1)
{
recvfrom(udpsock,buff,sizeof(buff),0,(struct sockaddr *)&s,&l);
sendto(udpsock,buff,sizeof(buff),0,(struct sockaddr *)&s,&l);
//LOG_PRINT("Successfully send and recieve");
}
return 0;
}
