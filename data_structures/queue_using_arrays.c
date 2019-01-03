//libraries needed
#include<stdio.h>

//assuming size of queue is 10
#define MAX 10
#define TRUE 1

//rear --> the position where enqueue is done
//front --> the position where dequeue is done
int queue[10]={0};
int front=-1,rear=0;
int enqueue();
int dequeue();
int count();
int display();

int main(){
	char choice;
	printf("\t\tQUEUE USING ARRAYS\n");
	printf("\t\t==================\n");
	printf("1--> Display the elements in the Queue\n");
	printf("2--> Count the number of elements in the Queue\n");
	printf("3--> Enqueue (Add an elements to the Queue)\n");
	printf("4--> Dequeue (Remove an element from the Queue)\n");
	printf("q--> Exit\n");
	printf("\nPlease choose an Option: ");
	while(TRUE){
		scanf(" %c",&choice);
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
				return 0;
			default:
				printf("\nInvalid Choice.\n");
				break;
		}
		printf("\n\nPlease choose an Option: ");
	}
	return 0;
}

int enqueue(){
	//check if queue is full
	if(rear==MAX){
		printf("\n\nQueue is full, Can\'t insert.\n");
		return -1;
	}
	//if it is the first element in the queue
	if(front==-1){
		front=0;
	}
	printf("\n\nEnter element to be inserted: ");
	scanf("%d",&queue[rear++]);
	printf("Element is successfully inserted into the Queue.\n");
	return 0;
}

int dequeue(){
	//check if queue is empty
	if(front==-1 || rear==front){
		printf("\n\nThe Queue is already Empty, Can\'t Dequeue\n");
		return -1;
	}
	printf("\n\nDequeued element from the Queue is: %d\n",queue[front++]);
	return 0;
}

int count(){
	//check if the queue is empty
	printf("\n\nThe number of Elements in the queue is: %d\n",(front==-1||rear==front)?0:rear-front);
	return 0;
}

int display(){
	if(front==-1 || rear==front){
		printf("\n\nThe Queue is Empty, No Elements to Display.\n");
		return -1;
	}
	printf("\n\nThe Elements in the Queue are:\t");
	//start from rear till front
	for(int nav=front;nav<rear;nav++){
		printf("%d  ",queue[nav]);
	}
	printf("\n");
	return 0;
}
