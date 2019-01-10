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
	printf("call %d %d\n",low,high);
	if(low>=high){
		return 0;
	}
	//consider first element as pivot
	int pivot=a[low];
	int i=low;
	int j=i+1;
	//fix pivot position
	while(j<=high){
		if(a[j]<=pivot){
			i=i+1;
			if(i!=j)
				swap(a+i,a+j);
		}
		j++;
	}
	swap(a+low,a+i);
	//split
	quick_sort(a,low,i-1);
	quick_sort(a,i+1,high);
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
