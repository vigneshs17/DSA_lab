#include<stdio.h>
#include<stdlib.h>

int main() {
	int n, temp;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int *p=(int*)malloc(n*sizeof(int)); //dynamically allocating memory
	//inputting the elements
	printf("Enter the elements:\n");
	for(int i=0;i<n;i++) {
		scanf("%d",p+i);
	}
	//bubble sort
	for(int i=0;i<n;i++) {
		for(int j=0;j<n-1;j++) {
			if(*(p+j)>*(p+j+1)) {
				temp=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=temp;
			}	
		}
	}
	//printing the sorted array
	for(int i=0;i<n;i++)
		printf("%d ",*(p+i));
	return 0;
}

