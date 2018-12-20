#include<stdio.h>

int printArray(int *,int);
int quick_sort(int *,int,int);
int swap(int *,int *);

int main(){
	int n;
	printf("\t\t\tQUICK SORT\n");
	printf("\t\t\t==========\n\n");
	printf("Enter the size of the Array: ");
	scanf("%d",&n);
	int a[n];
	int i,j;
	printf("Enter the elements of the Array: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	quick_sort(a,0,n-1);
	printf("\nElements of the Array after Sorting are: ");
	printArray(a,n);
	printf("\n");
	return 0;
}

int quick_sort(int *a,int low,int high){
	if(low>=high){
		return 0;
	}
	//consider mid as pivot
	int pivot=a[(low+high)/2];
	int i=low;
	int j=high;
	printArray(a+low,high+1);
	//fix pivot position
	while(i<j){
		printArray(a+low,high+1);
		while(i<=high && a[i]<pivot){
			i++;
		}
		while(j>=low && a[j]>pivot){
			j--;
		}
		if(i<j){
			swap(a+i,a+j);	
		}
	}
	//split
	quick_sort(a,low,j-1);
	quick_sort(a,j+1,high);
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
	return 0;
}
