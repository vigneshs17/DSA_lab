// Program to detect a loop in a linked list

#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
struct Node* head;
struct Node* start;
struct Node* loop;
int flag=0;
void insert(int elem) {
	struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
	struct Node* temp=head;
	if(head==NULL) {
		ptr->data=elem;
		head=ptr;
		return ;
	}
	while(temp->next!=NULL) {
		temp=temp->next;
	}
	temp->next=ptr;
	ptr->data=elem;
	ptr->next=NULL;
}

void print() {
	struct Node* ptr=head;
	while(ptr!=NULL) {
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

void createloop() {
	struct Node* ptr=head;
	int count=0, value, x;
	printf("Where do you want the loop to start?");
	scanf("%d",&x);
	if(head==NULL)
		 return;
	while(ptr->next!=NULL) {
		count++;
		ptr=ptr->next;
		if(ptr->data==x)
			start=ptr;
	}
	count++;
	printf("Where do you want to loop it?\n");
	scanf("%d",&value);
	ptr=head;
	/*
	
	for(int i=1;i<count;i++) {
		if(ptr->data==value) {
			loop=ptr;
			ptr=ptr->next;
		}
		else 
			ptr=ptr->next;
	}
	*/
	for(int i=1;i<count;i++) {
		if(ptr->data==value) {
			loop=ptr;
			ptr=ptr->next;
		}
		else
			ptr=ptr->next;
	}
	printf("loop is %d and start is %d",loop->data, start->data);
	start->next=loop;
	/*
	while(ptr->next!=NULL) {
		if(ptr==start) {
			ptr->next=loop;
			break;
		}
		ptr=ptr->next;
	}
	printf("Link is %d->%d",start->data, start->next->data);
	ptr->next=loop;*/
	printf("%d->%d", start->data, start->next->data);
	flag=1;
	
}

void find() {
	struct Node* ptr=head;
	while(ptr->next!=NULL) {
		ptr=ptr->next;
		if(ptr==loop) {
			printf("Loop exists.\n");
			return;
		}
	}
	printf("No loop\n");
}

void breakLoop() {
	if(flag==0) {
		printf("No loop exists!");
		return;
	}
	int x=0;
	struct Node* ptr=head;
	while(ptr->next!=loop) {
		ptr=ptr->next;
	}
	ptr=ptr->next;
	printf("%d",ptr->data);
	x=1;
	while(ptr->next!=loop) {
		ptr=ptr->next;
	}
	ptr->next=NULL;
}
int main() {
	int n, elem;
	head=NULL;
	loop=NULL;
	while(1) {
		printf("1.Insert an element:\n");
		printf("2.Check for a loop\n");
		printf("3.Print the linked list\n");
		printf("4.I want a loop\n");
		printf("5.I don't want a loop\n");
		printf("6.Break the loop\n");
		scanf("%d",&n);
		if(n==1) {
			printf("Enter the element:");
			scanf("%d",&elem);
			insert(elem);
		}
		else if(n==2)
			find(&loop);
		else if(n==3) {
			print();
		}
		else if(n==4) {
			createloop();
		}
		else if(n==5)
			continue;
		else if(n==6)
			breakLoop();
		else
			return 0;
		
	}
}
