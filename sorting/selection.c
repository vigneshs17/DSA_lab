#include<stdio.h>
#include<stdlib.h>

int main() {
	int n, temp, min;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int *p=(int*)malloc(n*sizeof(int));
	//inputting the elements
	printf("Enter the elements:\n");
	for(int i=0;i<n;i++) 
		scanf("%d",(p+i));
	//selection sort
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			min=*(p+i);
			if(min>*(p+j)) {
				min=*(p+i);
				*(p+i)=*(p+j);
				*(p+j)=min;
			}
		}
	}
	//printing the array
	for(int i=0;i<n;i++)
		printf("%d ",*(p+i));

	return 0;
}
		
