#include <stdio.h>
#include <stdlib.h>
//double linked list
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

void insert(int, int);
void removeElem(int);
int search(int);
void print();

struct Node* head;
void insert(int elem, int pos) {
	struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
	ptr->data=elem;
	ptr->next=NULL;
	ptr->prev=NULL;
	if(pos==1) {
		ptr->next=head;
		if(head!=NULL)
			head->prev=ptr;
		head=ptr;
		return;
	}
	struct Node *ptr1=head;
	
	for(int i=0;i<pos-2;i++) {
		ptr1=ptr1->next;
	}
	struct Node *ptr2=ptr1->next;
	if(ptr2!=NULL) {
		ptr->next=ptr1->next;
		ptr->prev=ptr2->prev;
		ptr1->next=ptr;
		ptr2->prev=ptr;
	}
	else {
		ptr1->next=ptr;
		ptr->prev=ptr1;
		ptr->next=NULL;
	}
	
}

void removeElem(int elem) {
	struct Node* ptr=head;
	struct Node* del;
	struct Node* ptr1; /*;
	int existence;
	existence=search(elem);
	printf("%d",existence);
	if(existence==0) {
		printf("Element can npt be deleted due to non-existence\n");
		return;
	}*/
	while(ptr->next->data!=elem) {
		ptr=ptr->next;
	}
	//del is the node containing the node to be deleted
	del=ptr->next;
	//ptr1 is the node succeeding the node to be deleted
	ptr1=del->next;
	ptr->next=ptr1;
	ptr1->prev=ptr;
}

int search(int elem) {
	struct Node* ptr=head;
	while(ptr->next!=NULL) {
		if(ptr->next->data==elem) {
			printf("Element found!");
			return 1;
		}
		ptr=ptr->next;
	}
	printf("Element does not exist!");
	return 0;
}

void print() {
	struct Node* ptr=head;
	printf("head");
	while(ptr!=NULL) {
		printf("<-%d->",ptr->data);
		ptr=ptr->next;
	}
	printf("NULL");
}


int main() {
	int n, elem, pos;
	struct Node* head=NULL;
	while(1) {
		printf("1. Insert an element\n");
		printf("2. Delete an element\n");
		printf("3. Search for an element\n");
		printf("4. Print the linked list\n");
		printf("5. Exit\n");
		printf("Enter option:");
		scanf("%d",&n);
		if(n==1) {
			printf("Enter the element and the position:\n");
			scanf("%d",&elem);
			scanf("%d",&pos);
			insert(elem, pos);
		}
		else if(n==2) {
			printf("Enter the element to be deleted:\n");
			scanf("%d",&elem);
			removeElem(elem);
		}
		else if(n==3) {
			printf("Enter the element to search for:\n");
			scanf("%d",&elem);
			search(elem);
		}
		else if(n==4) {
			print();
		}
		else
			return 0;
	}
}				 
