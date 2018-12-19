#include<stdio.h>

int swap(int *,int *);
int printArray(int *,int);

int main(){
	int n;
	printf("\t\t\tSELECTION SORT\n");
	printf("\t\t\t==============\n\n");
	printf("Enter the size of the Array: ");
	scanf("%d",&n);
	int a[n];
	int i,j;
	printf("Enter the elements of the Array: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++){
		int min=i;
		for(j=i+1;j<n;j++){
			if(a[min]>a[j]){
				min=j;
			}
		}
		if(min!=i){
			swap(a+i,a+min);
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
