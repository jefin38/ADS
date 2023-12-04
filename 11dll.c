#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *prev;
	struct node *next;
	int data;
};

struct node *new=NULL,*ptr=NULL,*head=NULL, *nextptr=NULL, *prevptr=NULL,*last=NULL;

void insertion_last();
void r_display();
void delete_last();
void insertion_beginning();
void delete_beginning();
void display();
void insert_after_key();
void delete();
void create_node();
void search();  
void main() {
	int opt;
	do {
	        printf("Doubly Linked List");
	        printf("\n-------------------\n \n");
		printf("1.Insertion Beginning  \n2.Insert after key \n3.Insertion last\n4.Delete beginning \n5.Delete last\n6.Delete specific Key \n7.Display \n8.Reverse display \n9.search \n10. exit"); 
		printf("\nChoose operation : ");
		scanf("%d",&opt);
		switch(opt) {
			case 1: insertion_beginning(); 
							break;
			case 2: insert_after_key();
							break;
			case 3: insertion_last();
							break;
			case 4: delete_beginning();
							break;
			case 5: delete_last();
							break;
			case 6: delete();
							break;
			case 7: display();  
							break;
			case 8: r_display();  
							break;	
			case 9: search();        
			                               break;			
			case 10:
			default:break;
		}
	} while(opt!=10);
}

void create_node() {
	new = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data to be inserted : ");
	scanf("%d",&new->data);
	new->next = NULL;
	new->prev = NULL;
}

void insertion_beginning() {
	create_node();
	if(head == NULL){
		head = new;
	} else {
		head->prev=new;
		new->next = head;
		head = new;
	}
}

void insertion_last() {
	create_node();
	if(head == NULL) {
		head = new;
	}
	else {
		ptr=head;
		while(ptr->next!=NULL){
			ptr = ptr->next;
		}
		ptr->next = new;
		new->prev = ptr;
	}
}



void insert_after_key() {
	int key;
	create_node();
	printf("Enter the key where the node to be inserted : ");
	scanf("%d",&key);
	ptr=head;
	while(ptr->data != key && ptr->next != NULL){
		ptr = ptr->next;
	}
	if(ptr->data == key){
		new->next = ptr->next;
		new->prev = ptr;
		ptr->next->prev = new;
		ptr->next = new;
	}
	else {
		printf("The key is not found\n ");
	}
}

void delete_beginning() {
	if(head == NULL){
		printf("Empty List");
	}
	else if(head->next == NULL) {
		head = NULL;
		free(head);
		printf("NODE DELETED\n");
	}
	else {
		ptr=head;
		head = head->next;
		head->prev = NULL;
		free(ptr);
		printf("NODE DELETED\n");
	}
}

void delete_last() {
	if(head == NULL) {
		printf("Empty List \n");
	} 
	else if(head->next == NULL) {
		head = NULL;
		free(head);
		printf("\n node deleted \n");  
	}
	else {
		ptr = head;
		while(ptr->next!=NULL){
			ptr = ptr->next;
		}
		ptr->prev->next = NULL;
		free(ptr);
		printf("\n node deleted \n");  
	}
}

void delete() {
	int key;
	printf("Enter the key where the node to be deleted : ");
	scanf("%d",&key);
	if(head->data == key){
		delete_beginning();
	}
	else {
		ptr=head;
		while(ptr->data != key && ptr->next != NULL){
			ptr = ptr->next;
		}
		if(ptr->data != key) {
		  printf("No data found \n");
		}
		else if(ptr->next == NULL) {
	    ptr->prev->next = NULL;
	    free(ptr);
	    printf("NODE DELETED \n");
	  }
	  else {
		  ptr->prev->next=ptr->next;
		  ptr->next->prev=ptr->prev;
		  free(ptr);
		  printf("NODE DELETED \n");
		}
	}
}

void display() {
	int c=0;
	
	if(head == NULL) {
		printf("Empty List \n");
	} else {
		printf("\n----------------------\n");
		ptr = head;
		while(ptr!=NULL){
			printf("%d ",ptr->data);
			c++;
			ptr = ptr->next;
			
		}
		printf("\n----------------------\n");
		printf("Number nodes: %d \n \n",c);
	}
}
void r_display(){
	if(head == NULL) {
		printf("Empty List \n");
	} else {
		
		printf("\n----------------------\n");
		ptr = head;
		while(ptr->next!=NULL){
			ptr = ptr->next;
		}
		last =ptr;
		while(last!=NULL){
			printf("%d ",last->data);
			last =last->prev;
		}
		
		printf("\n----------------------\n");
	}	
}



void search()  
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("\nitem found at location %d \n \n ",i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("\nItem not found\n");  
        }  
    }     
          
}  

