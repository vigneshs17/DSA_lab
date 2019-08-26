#include<stdio.h>
#include<stdlib.h>

int top=-1;

void push(int *arr,int elem, int size) {
	if(top==-1) {
		top++;
		*arr=elem;
		return;
	}
	if(top==size-1) {
		printf("Stack overflow.\n");
		return;

	}
	top++;
	*(arr+top)=elem;
}

void pop(int *arr) {
	if(top==-1) {
		printf("No element to pop.\n");
		return;
	}
	top--;
}

void peek(int *arr) {
	printf("Top element=%d\n",*(arr+top));
}
void search(int *arr, int elem) {
	for(int i=top;i>=0;i--) {
		if(*(arr+i)==elem) {
			printf("Element found at %d position from the top.\n",i);
			return;
		}
	}
	printf("Element does not exist in the stack.\n");
}

void print(int *arr) {
	printf("top->");
	for(int i=top;i>=0;i--) 
		printf("%d ",*(arr+i));
	printf("\n");
}

int main() {
	int size;
	int n, elem;
	printf("Enter the size of the stack: ");
	scanf("%d",&size);
	int *arr=(int*)malloc(sizeof(int)*size);
	while(1) {
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Search\n");
		printf("4.Print\n");
		printf("5.Peek\n");
		printf("6.Exit\n");
		printf("Enter choice: ");
		scanf("%d",&n);
		switch(n) {
		case 1:
			printf("Enter the element to push: ");
			scanf("%d",&elem);
			push(arr,elem,size);
			break;
		case 2:
			pop(arr);
			break;
		case 3:
			printf("Enter the element to be searched: ");
			scanf("%d",&elem);
			search(arr,elem);
			break;
		case 4:
			print(arr);
			break;
		case 5:
			peek(arr);
			break;
		default:
			return 0;
		}
	}
}	
