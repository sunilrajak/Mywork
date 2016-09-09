#include<stdio.h>

struct Bookinfo
{
//	char[20] bname;
	int pages;
	int price;
}book[3];

int main()
{
int i;
 for(i=0;i<3;i++)
   {
   // printf("ENter the name of Book");
   // gets(book[i].bname);
    printf("Enter the Number of pages");
    scanf("%d",book[i].pages);
    printf("Enter the price of Book");
    scanf("%d",book[i].price);
   }

printf("\n--------- Book Details ------------ ");
    
for(i=0;i<3;i++)
    {
  //  printf("\nName of Book    : %s",book[i].bname);
    printf("\nNumber of Pages : %d",book[i].pages);
    printf("\nPrice of Book   : %f",book[i].price);
    }    

return 0;
}

