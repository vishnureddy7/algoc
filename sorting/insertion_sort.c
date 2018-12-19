#include<stdio.h>

int swap(int *,int *);
int printArray(int *,int);

int main(){
	int n;
	printf("\t\t\tINSERTION SORT\n");
	printf("\t\t\t==============\n\n");
	printf("Enter the size of the Array: ");
	scanf("%d",&n);
	int a[n];
	int i,j;
	printf("Enter the elements of the Array: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++){
		int pos=i,k=a[i];
		while(pos>0 && k<a[pos-1]){
			a[pos]=a[pos-1];
			pos--;
		}
		a[pos]=k;
		printf("Iteration %d: ",i);
		printArray(a,n);
	}
	printf("\nElements of the Array after Sorting are: ");
	printArray(a,n);
	printf("\n");
	return 0;
}

int printArray(int *a,int n){
	for(int i=0;i<n;i++){
		printf("%d  ",a[i]);
	}
	printf("\n");
	return 0;
}

int swap(int *p,int *q){
	int temp=*p;
	*p=*q;
	*q=temp;
}
