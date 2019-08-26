#include<stdio.h>

int main() {
	int n,counter=0;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int arr[n],arr1[n];
	//taking input
	for(int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
	}
	//comparing the elements
	arr1[0]=1;
	for(int i=1;i<n;i++) {
		for(int j=0;j<=i;j++) {
			if(arr[j]>arr[i]) {
				arr1[i]=arr1[i-1]+1;
			}
			else {
				arr1[i]=arr1[i-1];
			}
		}
		printf("%d ", arr1[i]);
	}
	/*
	//printing the array
	for(int i=0;i<n;i++) {
		printf("%d ",arr1[i]);
	}*/
	return 0;

}
