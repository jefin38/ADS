#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
int data;
struct node *next;
};

typedef struct node node;

node *head = NULL;

void push() {
int data;
printf("\nEnter value: ");
scanf("%d", &data);
node *temp = (node *)malloc(sizeof(node));
if (temp == NULL) {
printf("Memory allocation failed.\n");
exit(EXIT_FAILURE);
}
temp->data = data;
temp->next = NULL;
if (head == NULL) {
head = temp;
} else {
node *pre = head;
while (pre->next != NULL) {
pre = pre->next;
}
pre->next = temp;
}
}
void pop() {
if (head == NULL) {
printf("\nStack Underflow\n");
} else {
node *temp = head;
if (head->next == NULL) {
free(head);
head = NULL;
} else {
 while (temp->next->next != NULL) {
temp = temp->next;
}
free(temp->next);
temp->next = NULL;
}
}
}
void display() {
if (head == NULL) {
printf("\nStack is Empty\n");
} else {
node *temp = head;
int count = 1;
while (temp != NULL) {
printf("Stack [%d] : %d\n", count, temp->data);
temp = temp->next;
 count++;
}
}
}
bool search(int val) {
node *temp = head;
while (temp != NULL) {
if (temp->data == val) 
{
return true;
}
temp = temp->next;
}
return false;
}
int main() {
int opt, value;
do {
printf("\n..................\n");
printf("1) PUSH\n");
printf("2) POP\n");
printf("3) DISPLAY\n");
printf("4) SEARCH\n");
printf("5) QUIT\n");
printf("\n..................\n");
printf("Choose your option: ");
scanf("%d", &opt);
switch (opt) {
case 1:
push();
break;
case 2:
pop();
break;
case 3:
display();
break;
case 4:
printf("\nEnter the value to search: ");
scanf("%d", &value);
if (search(value)) {
printf("\nElement %d found in the stack.\n", value);
} else {
printf("\nElement %d not found in the stack.\n", value);
}
break;
case 5:
exit(0);
default:
printf("\nInvalid Operation! Try Again...\n");
}
} while (1);
    return 0;
