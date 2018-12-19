#include<stdio.h>

int swap(int *,int *);
int printArray(int *,int);

int main(){
	int n;
	printf("\t\t\tBUBBLE SORT\n");
	printf("\t\t\t===========\n\n");
	printf("Enter the size of the Array: ");
	scanf("%d",&n);
	int a[n];
	int i,j;
	printf("Enter the elements of the Array: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j+1]<a[j]){
				swap(a+j,a+j+1);
			}
		}
		printf("Iteration %d: ",i+1);
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
