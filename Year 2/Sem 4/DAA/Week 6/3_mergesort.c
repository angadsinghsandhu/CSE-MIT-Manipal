#include <stdio.h>

int cnt=0;

void merge(int b[], int c[], int a[], int n1, int n2, int n){
	int i=0,j=0,k=0;

	while(i<n1 && j<n2){
		cnt++;
		if(b[i]<=c[j])
			a[k++]=b[i++];
		else
			a[k++]=c[j++];
	}
	while(i<n1){
		cnt++;
		a[k++]=b[i++];
	}
	while(j<n2){
		cnt++;
		a[k++]=c[j++];
	}
}

void mergesort(int a[], int n){
	if(n<=1)
		return;

	int b[n/2];
	int c[n/2+1];

	int n1=0,n2=0;

	for(int i=0;i<n/2;i++)
		b[n1++] = a[i];
	for(int i=n/2;i<n;i++)
		c[n2++] = a[i];

	mergesort(b,n1);
	mergesort(c,n2);

	merge(b,c,a,n1,n2,n);
}


void main(){
	int n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements: \n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	mergesort(arr,n);
	printf("Sorted: \n");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);

	printf("\nCount: %d",cnt);
}