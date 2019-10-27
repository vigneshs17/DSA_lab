#include<stdio.h>
#include<stdlib.h>
#include<math.h>

char stack[20];
char prefix[20];
int value[20];
int top=-1;
int top1=-1;
void push(char ch) {
        if(top>19) {
                printf("Stack overflow.\n");
                exit(1);
        }
        stack[++top]=ch;
}

void pushval(int x) {
        if(top1>19) {
                printf("Stack overflow 1.\n");
                exit(1);
        }
        value[++top1]=x;
}

char pop() {
        if(top<0) {
                printf("Stack underflow.\n");
                return 0;
        }
        return stack[top--];
}

int popval() {
        if(top1<0) {
                printf("Stack underflow 1.\n");
                return 0;
        }
        return value[top1--];
}

int isOperator(char token) {
        switch(token) {
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                        return 1;
                default:
                        return 0;
        }
}
int operation(int a, int b, int op) {
        switch(op) {
                case '+':
                        return (a)+(b);
                case '-':
                        return a-b;
                case '*':
                        return (a)*(b);
                case '/':
                        return a/b;
                case '^':
                        return pow((a),(b));
                default:
                        return 0;
        }
}

void eval() {
        int i=0, result, length=0;
        char token, op1, op2;
        while(prefix[i]!='\0') {
                length++;
                i++;
        }
        for(i=length-1;i>=0;i--) {
                token=prefix[i];
                if(token>='a'&&token<='z') {
            			int data;
            			printf("Enter the value: ");
            			scanf("%d",&data);
            			pushval(data);
            			continue;
                }
                else if(isOperator) {
                        op1=popval();
                        op2=popval();
                        result=operation(op1,op2,token);
                        pushval(result);
                }
        }
        printf("%d",value[top1]);
}
int main() {

        printf("Enter the prefix expression:");
        scanf("%s",prefix);
        eval();
        return 0;
}
