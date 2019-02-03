#include<stdio.h>

int linear_search(int *,int,int,int);
int max(int,int);

int main(){
	int n;
	printf("\t\t\tLINEAR SEARCH(recursive)\n");
	printf("\t\t\t========================\n\n");
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements of the array: ");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int k;
	printf("Enter the element to be searched: ");
	scanf("%d",&k);
	int index=linear_search(a,0,n-1,k);
	if(index>=0){
		printf("Element found at index: %d\n\n",index);
	}
	else{
		printf("Element not found in the array\n\n");
	}
	return 0;
}

int linear_search(int *a,int low,int high,int k){
	if(low>high){
		return -1;
	}
	if(high==low){
		if(a[low]==k){
			return high;
		}
		else{
			return -1;
		}
	}
	int mid=(low+high)/2;
	return max(linear_search(a,low,mid,k),linear_search(a,mid+1,high,k));
}

int max(int m,int n){
	return m>n?m:n;
}
