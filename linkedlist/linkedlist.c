#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
struct Node *head;
void insert(int elem, int pos) {
	struct Node* ptr=(struct Node*)malloc(sizeof(struct Node*));
	ptr->data=elem;
	ptr->next=NULL;
	if(pos==1) {
		ptr->next=head;
		head=ptr;
		return;
	}
	struct Node* ptr1=head;
	for(int i=0;i<pos-2;i++)
    {
        ptr1 = ptr1->next;
    }
	ptr->next=ptr1->next;
	ptr1->next=ptr;
}

void removeElem(int elem) {
	struct Node* ptr1=head;
	struct Node* ptr=ptr1->next;
	while(ptr1!=NULL) {
		ptr1=ptr1->next;
	}
	ptr1=head;
	while((ptr1->next)->data!=elem) {
		ptr1=ptr1->next;
	}
	ptr=ptr1->next;
	ptr1->next=ptr->next;
}

void print() {
	struct Node* ptr2=head;
	while(ptr2!=NULL) {
		printf("%d->",ptr2->data);
		ptr2=ptr2->next;
	}
	printf("\n");
}
/*
void reverse() {
	printf("function called");
	struct Node* ptr3=head;
	printf("test 1");
	int temp;
	printf("test 2");
	ptr3=ptr3->next;
	printf("test 3");
	head=0;
	printf("test 4");
	while(ptr3!=NULL) {
		temp=ptr3;
		ptr3=ptr3->next;
		ptr3->next=temp;
	}
}
*/
int main() {
	int n, elem, pos;
	head=NULL;
	
	while(1) {
		printf("1.Insert an element\n");
		printf("2.Delete an element\n");
		printf("3.Traverse the linked list\n");
		//printf("4.Reverse the linked list\n");
		printf("5.Exit\n");
		printf("Enter option: ");
		scanf("%d",&n);
		if(n==1) {
			printf("Enter the element and its position:\n");
			scanf("%d",&elem);
			scanf("%d",&pos);
			insert(elem, pos); }
		else if(n==2) {
			printf("Enter the element to be deleted:\n");
			scanf("%d",&elem);
			removeElem(elem); }
		else if(n==3) {
			print(); }
		/*else if(n==4) {
			printf("caliing the function");
			reverse();
		}*/
		else
			return 0;
	} 
}


