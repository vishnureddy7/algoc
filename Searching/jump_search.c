#include<stdio.h>
#include<math.h>

int main(){
	int n;
	printf("\t\t\tJUMP SEARCH\n");
	printf("\t\t\t===========\n\n");
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements of the array in sorted order: ");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int k,i,j,index=-1;
	printf("Enter the element to be searched: ");
	scanf("%d",&k);
	int jump=(int)sqrt(n);
	for(i=0;i<n;i+=jump){
		if(k<=a[i]){
			for(j=i;j>i-jump && j>=0;j--){
				if(k==a[j]){
					index=j;
				}
				else if(k>a[j]){
					break;
				}
			}
			break;
		}
	}
	if(index>=0){
		printf("Element is found at index: %d\n\n",index);
	}
	else{
		printf("Element not found in the array\n\n");
	}
	return 0;
}
