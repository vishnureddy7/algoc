#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define TRUE 1
#define MAX 10
//assuming maximum size of queue is 10

typedef struct node{
	int data;
	struct node *next;
}node;

node *front=NULL,*rear=NULL;
int num_ele=0;
int display();
int count();
int enqueue();
int dequeue();

int main(){
	printf("\t\tQUEUE USING LINKED LISTS\n");
	printf("\t\t========================\n");
	printf("1--> Display the elements in the Queue\n");
	printf("2--> Count the number of elements in the Queue\n");
	printf("3--> Enqueue (Add an element to the Queue)\n");
	printf("4--> Dequeue (Remove an element from the Queue)\n");
	printf("q--> Exit\n");
	printf("Please choose an Option");
	while(TRUE){
		char choice=getch();
		switch(choice){
			case '1':
				display();
				break;
			case '2':
				count();
				break;
			case '3':
				enqueue();
				break;
			case '4':
				dequeue();
				break;
			case 'q':
			case 'Q':
				exit(0);
			default:
				continue;
		}
		printf("\nPlease choose an Option");
	}
	return 0;
}

int enqueue(){
	//check if queue is full
	if(num_ele==10){
		printf("\n\nQueue is full, Can\'t insert.\n");
		return -1;
 	}
	int data;
	printf("\n\nEnter element to be inserted: ");
	scanf("%d",&data);
	//allocate memory to new the element
	node *new_ele=(node *)(malloc(sizeof(node)));
	new_ele->data=data;
	new_ele->next=NULL;
	//check if there are no elements in the queue
	if(rear==NULL){
		front=new_ele;
		rear=new_ele;
		num_ele=1;
		printf("Element is Successfully inserted into the Queue.\n");
		return 0;
	}
	//enqueue at front
	front->next=new_ele;
	front=new_ele;
	num_ele++;
	printf("Element is Successfully inserted into the Queue.\n");
	return 0;
}

int dequeue(){
	//check if queue is empty
	if(rear==NULL){
		printf("\n\nThe Queue is already empty, Can\'t dequeue.\n");
		return -1;
	}
	//dequeue at rear
	node *temp=rear;
	rear=rear->next;
	printf("\n\nDequeued Element from the queue is: %d\n",temp->data);
	free(temp);
	num_ele--;
	return 0;
}

int count(){
	printf("\n\nThe number of elements in the queue is: %d\n",num_ele);
	return 0;
}

int display(){
	//check if queue is empty
	if(rear==NULL){
		printf("\n\nThe Queue is Empty, No elements to Display.\n");
		return -1;
	}
	//start from rear till front
	node *nav=rear;
	printf("\n\nThe elements in the Queue are: ");
	while(nav!=NULL){
		printf("%d-->",nav->data);
		nav=nav->next;
	}
	printf("NULL\n");
	return 0;
}

