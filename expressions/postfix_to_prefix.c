#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char str[20],stack[20];
int top=-1;
void push(char c) {
   stack[++top]=c;
}

char pop() {
return stack[top--];
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

void reverse(char array[30]) {
	int i,j;
	char temp[100];
	for (i=strlen(array)-1,j=0;i+1!=0;--i,++j) {
		temp[j]=array[i];
	}
	temp[j]='\0';
	strcpy(array,temp);
}

void postfix_to_prefix() {
  int n,i,j=0;
  char prefix[20], a,b,op;
  printf("Enter the postfix expression\n");
  scanf("%s",str);
  n=strlen(str);
  for(int i=0;i<20;i++)
     stack[i]='\0';
  printf("Prefix expression is:\n");
  for(i=n-1;i>=0;i--) {
       if(isOperator(str[i])) {
         push(str[i]);
        }

        else {
          prefix[j++]=str[i];
          while((top!=-1)&&(stack[top]=='@')) {
              a=pop();
              prefix[j++]=pop();
          }
          push('@');
        }
  }
  prefix[j]='\0';
  reverse(prefix);
  printf("%s\n",prefix);
}
int main() {
  postfix_to_prefix();
  return 0;
}
