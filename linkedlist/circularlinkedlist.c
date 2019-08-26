#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
};


struct Node* insertEmpty(struct Node* last, int data) {
	
	if(last!=NULL) 
		return last;
		
	struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
	ptr->data=data;
	last=ptr;
	last->next=last;
	printf("insert empty");
	return last;
}
struct Node* insertStart(struct Node* last, int data) {

	printf("Insertstart0 works");
	if(last==NULL) {
		return insertEmpty(last,data);
	}
	printf("Insertstart1 works");
	struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
	printf("Insertstart2 works");
	ptr->data=data;
	ptr->next=last->next;
	printf("Insertstart3 works");
	last->next=ptr;
	printf("Insertstart works");
	return last;
}

struct Node* insertEnd(struct Node* last, int data) {
	
	
	if(last==NULL) {
		return insertEmpty(last,data);
	}
	struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
	ptr->data=data;
	ptr->next=last->next;
	last->next=ptr;
	last=ptr;
	printf("Insertend works");
	return last;
}

struct Node* insert(struct Node* last, int data, int previous) {
	while(last->data!=previous) {
		last=last->next;
	}
	//take care of the case when previous does not exist in the linked list
	struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
	ptr->data=data;
	ptr->next=last->next;
	last->next=ptr;
	last=ptr;
	printf("Insert works");
	return last;
}

struct Node* removeElem(struct Node* last, int data) {
	while(last->next->data!=data) {
		last=last->next;
	}
	struct Node* ptr=last->next;
	last->next=ptr->next;
	last=ptr;
	printf("remove works");
	return last;
}

void print(struct Node* last) {
	struct Node* ptr=last->next;
	if(ptr!=NULL) {
		do {
			printf("%d->",ptr->data);
			ptr=ptr->next;
		} while(ptr!=last);
	}
	printf("%d",last->data);
	printf("\n");
}
int main() {
	int n, elem, previous;
	struct Node* last=NULL;
	
	while(1) {
		printf("1.Insert an element at the beginning\n");
		printf("2.Insert an element at the end\n");
		printf("3.Insert an element after an element\n");
		printf("4.Delete an element\n");
		printf("5.Traverse the linked list\n");
		printf("6.Exit\n");
		printf("Enter option: ");
		scanf("%d",&n);
		if(n==1) {
			printf("Enter the element:\n");
			scanf("%d",&elem);
			last=insertStart(last,elem); }
		else if(n==2) {
			printf("Enter the element:\n");
			scanf("%d",&elem);
			last=insertEnd(last,elem); }
		else if(n==3) {
			printf("Enter the element:\n");
			scanf("%d",&elem);
			scanf("%d",&previous);
			last=insert(last,elem,previous); }
		else if(n==4) {
			printf("Enter the element to be deleted:\n");
			scanf("%d",&elem);
			removeElem(last,elem); }
		else if(n==5) {
			print(last); }
		else
			return 0;
	} 
}