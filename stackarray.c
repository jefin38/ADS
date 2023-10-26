#include<stdio.h>
int stack[100],choice,n,top=-1,x,i;
void push();
void pop();
void display();

int main()
{
printf("\n Enter the size of stack:");
scanf("%d",&n);
printf("\n1.Push 2.Pop  3.Display  4.Exit");

do
{
printf("\n Enter Choice:");
scanf("%d",&choice);
switch(choice)
{
case 1: 
{
push();
break;
}
case 2:
{
pop();
break;
}
case 3:
{
display();
break;
}
case 4:
{
printf("\n\t Exit");
break;
}
default:
{
printf ("\n\t Please Enter a Valid Choice 1 to 4");
}     
}
}
while(choice!=4);
return 0;
}
void push()
{
if(top>=n-1)
{
printf("\n\tSTACK is overflow");
}
else
{
printf(" Enter elemnt to be pushed:");
scanf("%d",&x);
top++;
stack[top]=x;
}
}
void pop()
{
if(top<=-1)
{
printf("\n\t Stack is under flow");
}
else
{
printf("\n\t The popped elements is %d",stack[top]);
top--;
}
}
void display()
{
if(top>=0)
{
printf("\n The elements in STACK are \n");
for(i=top; i>=0; i--)
printf("\n%d",stack[i]);
printf("\n Press Next Choice");
}
else
{
printf("\n The STACK is empty");
}
   
}
