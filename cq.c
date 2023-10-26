#include <stdio.h>   
#define max 20
int queue[max],front=-1,rear=-1,choice=1,x, i, flag=0;
void enqueue(int element)  
{  
if(front==-1 && rear==-1)  
{  
front=0;  
rear=0;  
queue[rear]=element;  
}  
else if((rear+1)%max==front)  
{  
printf("Queue is overflow..");  
}  
else  
{  
rear=(rear+1)%max;    
queue[rear]=element;    
}  
}  
int dequeue()  
{  
if((front==-1) && (rear==-1))  
{  
printf("\nQueue is underflow..");  
}  
else if(front==rear)  
{  
printf("\n The dequeued element is %d", queue[front]);  
front=-1;  
rear=-1;  
}   
else  
{  
printf("\n The dequeued element is %d", queue[front]);  
front=(front+1)%max;  
}  
}  


void search()
{
int  f=0, i, k;
if(front==-1)
{
printf("queue is empty ");
}
printf("enter element to search");
scanf("%d", &k);
for (i=0; i<=max; i++)
{
if(queue[i]==k)
{
f=1;
break;
}}
if(f==1)
{
printf("element found at location %d", i+1);
}
else
{
printf("element not found.");
}
}

void display()  
{  
int i=front;  
if(front==-1 && rear==-1)  
{  
printf("\n Queue is empty");  
}  
else  
{  
printf("\n Elements in a Queue are :");  
while(i<=rear)  
{  
printf("%d ", queue[i]);  
i=(i+1)%max;  
}  
}  
}  
int main()  
{  
while(choice<5 && choice!=0) 
{  
printf("\n 1: Insert element");  
printf("\n 2: Delete element");  
printf("\n 3: Display elements");  
printf("\n 4: search elements");  
printf("\n Enter your choice");  
scanf("%d", &choice);   
switch(choice)  
{  	
case 1:  
printf("Enter the element to be inserted");  
scanf("%d", &x);  
enqueue(x);  
break;  
case 2:  
dequeue();  
break;  
 case 3:  
display(); 
break; 

 case 4:  
search(); 
break; 
}}  
return 0;  
} 
