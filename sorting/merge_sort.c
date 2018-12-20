#include<stdio.h>

int printArray(int *,int);
int split(int *,int,int);
int merge(int *,int,int,int);

int main(){
	int n;
	printf("\t\t\tMERGE SORT\n");
	printf("\t\t\t==========\n\n");
	printf("Enter the size of the Array: ");
	scanf("%d",&n);
	int a[n];
	int i,j;
	printf("Enter the elements of the Array: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	split(a,0,n-1);
	printf("\nElements of the Array after Sorting are: ");
	printArray(a,n);
	printf("\n");
	return 0;
}

int split(int *a,int low,int high){
	if(low==high){
		return 0;
	}
	int mid=(low+high)/2;
	//split
	split(a,low,mid);
	split(a,mid+1,high);
	//merge
	merge(a,low,mid,high);
	return 0;
}

int merge(int *a,int low,int mid,int high){
	int n1=mid-low+1;
	int n2=high-mid;
	int left[n1];
	int right[n2];
	//copy to temporary arrays
	for(int i=0;i<n1;i++){
		left[i]=a[low+i];
	}
	for(int i=0;i<n2;i++){
		right[i]=a[mid+i+1];
	}
	int i=0,j=0,k=low;
	while(i<n1 && j<n2){
		if(left[i]<right[j]){
			a[k++]=left[i++];
		}
		else{
			a[k++]=right[j++];
		}
	}
	while(i<n1){
		a[k++]=left[i];
		i++;
	}
	while(j<n2){
		a[k++]=right[j];
		j++;
	}
	return 0;
}

int printArray(int *a,int n){
	for(int i=0;i<n;i++){
		printf("%d  ",a[i]);
	}
	printf("\n");
	return 0;
}
