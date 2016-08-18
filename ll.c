#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *next;
};

void push(struct node** head_ref, int new_data)
{

    struct node* new_node = (struct node*) malloc(sizeof(struct node));


    new_node->data  = new_data;


    new_node->next = (*head_ref);


    (*head_ref)    = new_node;
}


int main()
{
struct node* head=NULL;
struct node* second=NULL;
struct node* third=NULL;

head=(struct node*)malloc(sizeof(struct node));
second=(struct node*)malloc(sizeof(struct node));
third=(struct node*)malloc(sizeof(struct node));

head->data=100;
head->next=second;

second->data=200;
second->next=third;

third->data=300;
third->next=NULL;

//printf("%d",third->data);
push(head,25);
printf("%d",head->data);
return 0;
}

