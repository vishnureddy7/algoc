#include<stdio.h>
#include<math.h>

int radix_sort(int*, int, int);

int main(){
	int n;
	printf("\t\t\tRADIX SORT\n");
	printf("\t\t\t==========\n\n");
	printf("Enter the size of the Array: ");
	scanf("%d",&n);
	int a[n];
	int i,j;
	printf("Enter the elements of the Array: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int max_pow=0;
	for(i=0;i<n;i++){
		int p=ceil(log10(a[i]));
		if(p>max_pow){
			max_pow=p;
		}
	}
	max_pow+=1;
	for(i=1;i<max_pow;i++){
		radix_sort(a,(int)pow(10,i),n);
		printf("\nIteration %d: ",i);
		for(j=0;j<n;j++){
			printf("%d ",a[j]);
		}
	}
	printf("\n\nElements of the Array after Sorting are: ");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}

int radix_sort(int *a,int base,int n){
	int b[n];
	int k=0;
	for(int i=0;i<10;i++){
		for(int j=0;j<n;j++){
			if((a[j]/(base/10))%10==i){
				b[k++]=a[j];
			}
		}
	}
	for(int i=0;i<n;i++){
		a[i]=b[i];
	}
	return 0;
}
