#include<stdio.h>

int binary_search(int *,int,int,int);

int main(){
	int n;
	printf("\t\t\tBINARY SEARCH(recursive)\n");
	printf("\t\t\t========================\n\n");
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
	int index=binary_search(a,0,n-1,k);
	if(index>=0){
		printf("Element found at index: %d\n\n",index);
	}
	else{
		printf("Element not found in the array\n\n");
	}
	return 0;
}

int binary_search(int *a,int low,int high,int k){
	if(low>high){//element not found
		return -1;
	}
	int mid=(low+high)/2;
	if(a[mid]==k){//found
		return mid;
	}
	else if(k<a[mid]){//left half
		return binary_search(a,low,mid-1,k);
	}
	else{//right half
		return binary_search(a,mid+1,high,k);
	}
}
