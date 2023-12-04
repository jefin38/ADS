#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
int data;
struct node*next;
};
struct node *head=NULL;


void insertfirst()
{
struct node*newnode;
newnode=(struct node*)malloc(sizeof(struct node*));
{
printf("\n enter the element to be inserted :"); 
scanf("%d",&newnode->data);
{
newnode->next=head; 
head=newnode;
}
printf("\n %d inserted into the list",newnode->data);
}
}


void insertlast()
{
struct node*temp,*newnode;
newnode=(struct node*)malloc(sizeof(struct node*));
newnode->next=NULL;
temp=head;
while(temp->next!=NULL)
temp=temp->next;
printf("\n enter the element to be inserted :"); 
scanf("%d",&newnode->data);
temp->next=newnode;
printf("\n %d inserted into the list",newnode->data);
}



void insertlocation()
{
int key;
struct node *temp, *newnode;
newnode=(struct node*)malloc(sizeof(struct node*)); 
newnode->next=NULL;
printf("\n enter the value of node after new node to be inserted :");
scanf("%d",&key);
temp=head;
while(temp->data!=key)
{
temp=temp->next;
if(temp==NULL)
break;
}
if(temp==NULL)
{
printf("The %d value not exist",key);
return;
}
if(temp->data==key)
{
printf("\n enter the element to be inserted :"); 
scanf("%d",&newnode->data); 
newnode->next=temp->next; 
temp->next=newnode;
printf("\n %d inserted after %d",newnode->data,key);
}
}


void deletefirst()
{
struct node*temp;
temp=head;
head=temp->next;
printf("%d deleted",temp->data);
free(temp);
}


void deletelast()
{
struct node*temp,*p;
temp=head;
while(temp->next!=NULL)
{
p=temp;
temp=temp->next;
}
printf("%d deleted",temp->data);
free(temp);
p->next=NULL;
}


void deletelocation()
{
struct node*temp,*p;
int key;
printf("\n enter the value of node to be deleted :");
scanf("%d",&key);
temp=head;
while(temp->data!=key)
{
p=temp;
temp=temp->next;
if(temp==NULL)
break;
}
if(temp==NULL)
{
printf("The %d value not exist",key);
return;
}
if(temp->data==key)
{
printf("%d deleted",temp->data);
if(temp==head)
{
p=head;
head=temp->next;
free(p);
}
else
{
p->next=temp->next;
free(temp);
}
}
}
void search()
{
struct node*temp;
int key,pos=0;
temp=head;
printf("\n enter the element to search :");
scanf("%d",&key);
while(temp->data!=key)
{
temp=temp->next;
pos++;
if(temp==NULL)
break;
}
if(temp==NULL)
{
printf("\n The %d value not found",key);
return;
}
if(temp->data==key)
{
printf("\n %d value available in location %d",key,pos+1);
}
}


void display()
{
struct node*p;
if(head==NULL)
printf("list is empty");
else
{
printf("\n elements in linked list are:");
p=head;
while(p!=NULL)
{
printf("\t%d",p->data);
p=p->next;
}
}
}


void main()
{
int choice;
printf("Singly linked list");
do
{
printf("\n\n 1.insert at first \n 2.insert at last\n 3.insert at any specified location \n 4.delete from first\n 5.delete from last\n 6.delete node after specified location \n 7.search for an element \n 8. display \n 9. exit\n" ); 
printf("\n enter a choice :");
scanf("%d",&choice);
switch(choice)
{
case 1:insertfirst();
break;
case 2:insertlast();
break;
case 3:insertlocation();
break;
case 4:deletefirst();
break;
case 5:deletelast();
break;
case 6:deletelocation();
break;
case 7:search();
break;
case 8:display();
break;
case 9:exit(0);
printf("exiting the program ");
return;

default:printf("\n invalid option");
}
}
while(choice!=9);
}
