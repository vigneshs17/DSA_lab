#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* top;

void push(int elem) {
	struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
	if(top==NULL) {
		new_node->data=elem;
		new_node->next=NULL;
		top=new_node;
		return;
	}
	new_node->data=elem;
	new_node->next=top;
	top=new_node;
}

void pop() {
	struct Node *ptr=top;
	if(top==NULL) {
		printf("No element to pop.\n");
		return;
	}
	top=ptr->next;
	free(ptr);
}

void peek() {
	printf("Top element: %d\n", top->data);
}

void print() {
	struct Node *ptr=top;
	printf("top->");
	while(ptr!=NULL) {
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL\n");
}

void search(int elem) {
	struct Node *ptr=top;
	while(ptr->data!=elem) {
		ptr=ptr->next; 
		if(ptr==NULL) {
			printf("Element does not exist in the stack.\n");
			return;
		}
	}
	printf("Element found.\n");
}

int main() {
	top=NULL;
	int elem, n;
	while(1) {
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Peek\n");
		printf("4.Print\n");
		printf("5.Search\n");
		printf("6.Exit\n");
		printf("Enter choice: ");
		scanf("%d",&n);
		switch(n) {
			case 1:
				printf("Enter element to push: ");
				scanf("%d",&elem);
				push(elem);
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				print();
				break;
			case 5:
				printf("Enter the element you want to search for: ");
				scanf("%d",&elem);
				search(elem);
				break;
			default:
				return 0;
		}
	}
}
