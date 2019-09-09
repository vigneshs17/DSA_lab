//Infix expression to prefix expre

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char stack[20], infix[20], postfix[20];
int top=-1;
void push(char ch);
char pop();
int precedence(char token);
int isOperator(char token);
void reverse(char array[20]);
void push(char ch) {
  if(top>=19) {
    printf("Stack overflow!\n");
    return;
  }
  stack[++top]=ch;
}

char pop() {
  if(top<0) {
    printf("Stack underflow!\n");
    return '$';
  }
  return stack[top--];
}

int precedence(char token) {
  if(token=='^')
    return 3;
  else if(token=='*' || token=='/')
    return 2;
  else if(token=='+' || token=='-')
    return 1;
  else
    return 0;
}

int isOperator(char ch) {
  switch(ch) {
    case '^':
    case '*':
    case '/':
    case '+':
    case '-':
      return 1;
    default:
      return 0;
    }
}

void infix_to_prefix(char infix[20],char prefix[20]) {
	int i,j=0;
	char symbol;
	stack[++top]='#';
	reverse(infix);
	for (int i=0;i<strlen(infix);i++) {
		symbol=infix[i];
		if (symbol>='a'&&symbol<='z') {
			prefix[j]=symbol;
			j++;
		} else {
			if (symbol==')') {
				push(symbol);
			} else if(symbol == '(') {
				while (stack[top]!=')') {
					prefix[j]=pop();
					j++;
				}
				pop();
			} else {
				if (precedence(stack[top])<=precedence(symbol)) {
					push(symbol);
				} else {
					while(precedence(stack[top])>=precedence(symbol)) {
						prefix[j]=pop();
						j++;
					}
					push(symbol);
				}
				//end for else
			}
		}
		//end for else
	}
	//end for for
	while (stack[top]!='#') {
		prefix[j]=pop();
		j++;
	}
	prefix[j]='\0';
}

void reverse(char array[30]) {
	int i,j;
	char temp[100];
	for (i=strlen(array)-1,j=0;i+1!=0;--i,++j) {
		temp[j]=array[i];
	}
	temp[j]='\0';
	strcpy(array,temp);
}

int main() {
	char infix[20],prefix[20],temp;
	printf("Enter infix operation: ");
	gets(infix);
	infix_to_prefix(infix,prefix);
	reverse(prefix);
	puts((prefix));
}
