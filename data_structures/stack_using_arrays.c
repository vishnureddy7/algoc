//libraries needed
#include<stdio.h>

//assuming size of stack is 10
#define MAX 10
#define TRUE 1

int stack[10]={0};
int top=-1;

int push();
int pop();
int count();
int display();

int main(){
    char choice;
	printf("\t\tSTACK_USING_ARRAYS\n");
	printf("\t\t==================\n");
	printf("1--> Display the elements in the Stack\n");
	printf("2--> Count the number of elements in the Stack\n");
	printf("3--> Push (Insert an element into the Stack)\n");
	printf("4--> Pop (Remove an element from the Stack)\n");
	printf("q--> Quit\n");
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
				push();
				break;
			case '4':
				pop();
				break;
			case 'q':
			case 'Q':
				return 0;
			default:
				printf("\nInvalid Choice.\n");
		}
		printf("\nPlease choose an Option: ");
	}
	return 0;
}

int display(){
	//check if the stack is empty
	if(top==-1){
		printf("\n\nStack is empty, No elements to display.\n");
		return -1;
	}
	printf("\n\nThe Elements in the Stack are:\t");
	//start from top till 0
	for(int i=top;i>=0;i--){
		printf("%d ",stack[i]);
	}
	printf("\n");
	return 0;
}

int count(){
	printf("\n\nThe number of elements in the Stack is: %d\n",top+1);
	return 0;
}

int push(){
	//check if the stack is full
	if(top+1==MAX){
		printf("\n\nStack Overflow (Stack is full, Can\'t insert).\n");
		return -1;
	}
	printf("\n\nPlease enter the element to be inserted: ");
	scanf("%d",&stack[++top]);
	printf("Element is successfully pushed into the Stack.\n");
	return 0;
}

int pop(){
	//check if the stack is empty
	if(top==-1){
		printf("\n\nStack Underflow (Stack is already empty, Can\'t delete).\n");
		return -1;
	}
	printf("\n\nPopped Element from the Queue is: %d\n",stack[top--]);
	return 0;
}
