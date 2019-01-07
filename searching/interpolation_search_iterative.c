#include<stdio.h>

int main(){
	int n;
	printf("\t\t\tINTERPOLATION SEARCH(iterative)\n");
	printf("\t\t\t==============================\n\n");
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements of the array in sorted order: ");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int k;
	printf("Enter the element to be searched: ");
	scanf("%d",&k);
	int low=0;
	int high=n-1;
	int mid;
	while(low<=high){
		mid=low+((high-low)/(a[high]-a[low]))*(k-a[low]);
		if(k<a[mid]){//left half
			high=mid-1;
		}
		else if(k>a[mid]){//right half
			low=mid+1;
		}
		else{//found
			break;
		}
	}
	if(a[mid]==k){
		printf("Element found at index: %d\n\n",mid);
	}
	else{
		printf("Element not found in the array\n\n");
	}
	return 0;
}
