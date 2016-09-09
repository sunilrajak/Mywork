#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
void main()
{
int cl;
char buff[100]="djkbfkudshfdshfoisdnf";
struct sockaddr_in server;
int l;

cl=socket(PF_INET,SOCK_DGRAM,0);
server.sin_family = AF_INET;
server.sin_port = htons(7891);
server.sin_addr.s_addr = inet_addr("127.0.0.1");

l=sizeof(server);

while(1)
{
gets(buff);
sendto(cl,buff,sizeof(buff),0,(struct sockaddr *)&server,l);
recvfrom(cl,buff,sizeof(buff),0,NULL,NULL);
printf("This is revc ");
puts(buff);
}
return 0;
}
