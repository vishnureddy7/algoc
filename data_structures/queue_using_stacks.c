//libraries and definations
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define TRUE 1

//structure of node
typedef struct node{
	int data;
	struct node *next;
}node;

//stack operations
int push(node **,int);
int pop(node **);
int count(node **);
int increment_count(node **);
int decrement_count(node **);
int display_reverse(node *);

//queue operations
int enqueue();
int dequeue();
int display();

node *top1=NULL;
node *top2=NULL;
int stack1_count=0;
int stack2_count=0;

int main(){
	printf("\t\tQUEUE IMPLIMENTATION USING STACK\n");
	printf("\t\t================================\n\n");
	printf("1--> Display Queue Elements\n");
	printf("2--> Enqueue(Insert an element into the Queue)\n");
	printf("3--> Dequeue(Delete an element from the Queue)\n");
	printf("0--> Exit");
	while(TRUE){
		int ch;
		printf("\nPlease enter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				display();
				break;
			case 2:
				enqueue();
				break;
			case 3:
				dequeue();
				break;
			case 0:
				return 0;
			default:
				printf("\nInvalid Choice.\n");
		}
	}
	return 0;
}

//queue opearations
int enqueue(){
	if(stack1_count==10){
		printf("\nQueue is full, Can\'t Enqeue.\n");
		return -1;
	}
	int data;
	printf("\nPlease enter the data element: ");
	scanf("%d",&data);
	//to enqueue just push the element to stack1
	push(&top1,data);
	printf("\nElement Successfully enqueued into the Queue.\n");
	return 0;
}

int dequeue(){
	if(stack1_count==0){
		printf("\nThe Queue is already empty, Can\'t Dequeue.\n");
		return -1;
	}
	//to dequeue first pop all the elements from stack1 and push them to stack2
	//pop an element of stack2 and print it(which is the dequeued element)
	//pop all the remaining elements of stack2 and push them to stack1
	int temp=0;
	temp=pop(&top1);
	do{
		push(&top2,temp);
		temp=pop(&top1);
	}while(temp!=-1);
	temp=pop(&top2);
	printf("\nDequeued element from the Queue is: %d\n",temp);
	temp=pop(&top2);
	while(temp!=-1){
		push(&top1,temp);
		temp=pop(&top2);
	}
	return 0;
}

int display(){
	if(stack1_count==0){
		printf("\nThere are no elements in the queue to display.\n");
		return -1;
	}
	printf("\nThe elements of the Queue are: ");
	//to display the queue elements print the stack1 in reverse order
	display_reverse(top1);
	printf("\n");
	return 0;
}

//stack operations
int push(node **top,int data){
	if(count(top)==10)
		return -1;
	node *new_node=(node *)malloc(sizeof(node));
	new_node->data=data;
	new_node->next=*top;
	*top=new_node;
	increment_count(top);
	return 0;
}

int pop(node **top){
	if(count(top)==0)
		return -1;
	node *old_node=*top;
	int data=old_node->data;
	*top=(*top)->next;
	free(old_node);
	decrement_count(top);
	return data;
}

int count(node **top){
	if(top==&top1)
		return stack1_count;
	return stack2_count;
}

int increment_count(node **top){
	if(top==&top1)
		stack1_count++;
	else
		stack2_count++;
	return 0;
}

int decrement_count(node **top){
	if(top==&top1)
		stack1_count--;
	else
		stack2_count--;
	return 0;
}

int display_reverse(node *top){
	if(top==NULL)
		return 0;
	display_reverse(top->next);
	printf("%d ",top->data);
}
