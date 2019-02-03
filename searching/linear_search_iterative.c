#include<stdio.h>

int main(){
	int n;
	printf("\t\t\tLINEAR SEARCH(iterative)\n");
	printf("\t\t\t=======================\n\n");
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements of the array: ");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int k,i;
	printf("Enter the element to be searched: ");
	scanf("%d",&k);
	for(i=0;i<n;i++){
		if(a[i]==k){
			printf("Element is found at index: %d\n\n",i);
			break;
		}
	}
	if(i==n){
		printf("Element not found in the array\n\n");
	}
	return 0;
}
