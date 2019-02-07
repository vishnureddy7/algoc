#include<stdio.h>

int insert_sort(int*, int);

int main(){
	int n;
	printf("\t\t\tBUCKET SORT\n");
	printf("\t\t\t===========\n\n");
	printf("Enter the size of the Array: ");
	scanf("%d",&n);
	int a[n];
	int i,j,k;
	//assuming the number of buckets is 10
	int bucket[10][n];
	int count[10];
	printf("Enter the elements of the Array: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	//divide the items into 10 buckets based on range (0,9)->bucket0, (10,19)->bucket1,etc
	for(i=0;i<10;i++){
		k=0;
		for(j=0;j<n;j++)
			if(a[j]/10==i)
				bucket[i][k++]=a[j];
		//store the count of each bucket in count array
		count[i]=k;
	}
	//sort each bucket individually using insertion sort
	for(i=0;i<10;i++)
		insert_sort(bucket[i],count[i]);
	k=0;
	//store the elements of buckets back to the array in order
	for(i=0;i<10;i++)
		for(j=0;j<count[i];j++)
			a[k++]=bucket[i][j];
	//print the elements after sorting
	printf("\n\nElements of the Array after Sorting are: ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}

//code for insertion sort
int insert_sort(int *a,int n){
	for(int i=1;i<n;i++){
		int pos=i;
		int k=a[i];
    while(pos>0 && k<a[pos-1]){
      a[pos]=a[pos-1];
      pos--;
    }
    a[pos]=k;
  }
	return 0;
}
