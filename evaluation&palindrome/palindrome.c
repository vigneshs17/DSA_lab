#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str1[50], str2[50], stack[50];
int top=-1;
int length=0;
void push(char ch) {
	if(top>50) {
		printf("Stack overflow.\n");
		exit(1);
	}
	stack[++top]=ch;
}

char pop() {
	if(top<0) {
		printf("Stack underflow.\n");
		return 0;
	}
	return stack[top--];
}

void palindrome() {
	int j=0;
	int result;
	while(str1[j]!='\0') {
		length++;
		j++;
	}
	for(int i=0;i<length;i++) {
		push(str1[i]);
	}
	for(int i=0;i<length;i++) {
		str2[i]=pop();
	}
	result=strcmp(str1,str2);
	if(result==0) 
		printf("Palindrome.\n");
	else
		printf("Not a palindrome.\n");
}
int main() {
	printf("Enter the string: ");
	scanf("%s",str1);
	palindrome();
	return 0;
}
