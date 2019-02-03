#include<stdio.h>

int main(){
	int n;
	printf("\t\t\tCOUNTING SORT\n");
	printf("\t\t\t=============\n\n");
	printf("Enter the range of the Array elements: ");
	int k;
	scanf("%d",&k);
	printf("Enter the size of the Array: ");
	scanf("%d",&n);
	int a[n];
	int i,j;
	printf("Enter the elements of the Array: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int count[k+1];
	//initialize counts to zeros
	for(i=0;i<k+1;i++){
		count[i]=0;
	}
	//count each data element
	for(i=0;i<n;i++){
		count[a[i]]++;
	}
	printf("\nElements of the Array after Sorting are: ");
	for(i=0;i<=k;i++){
		for(j=0;j<count[i];j++){
			printf("%d ",i);
		}
	}
	printf("\n");
	return 0;
}
