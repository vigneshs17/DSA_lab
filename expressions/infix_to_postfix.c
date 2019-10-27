//Infix expression to postfix expression
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char stack[20], infix[20], postfix[20];
int top=-1;

void push(char ch) {
  if(top>=19) {
    printf("Stack overflow!\n");
    return;
  }
  top=top+1;
  stack[top]=ch;
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
void infix_to_postfix() {
	int i, j;
	char item;
	char x;

	push('(');                               /* push '(' onto stack */
	strcat(infix,")");                  /* add ')' to infix expression */

	i=0;
	j=0;
	item=infix[i];         /* initialize before loop*/

	while(item != '\0')        /* run loop till end of infix expression */
	{
		if(item == '(')
		{
			push(item);
		}
		else if( item>='a'&&item<='z')
		{
			postfix[j] = item;              /* add operand symbol to postfix expr */
			j++;
		}
		else if(isOperator(item) == 1)        /* means symbol is operator */
		{
			x=pop();
			while(isOperator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix[j] = x;                  /* so pop all higher precendence operator and */
				j++;
				x = pop();                       /* add them to postfix expresion */
			}
			push(x);

			push(item);                 /* push current oprerator symbol onto stack */
		}
		else if(item == ')')         /* if current symbol is ')' then */
		{
			x = pop();                   /* pop and keep popping until */
			while(x != '(')                /* '(' encounterd */
			{
				postfix[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{ /* if current symbol is neither operand not '(' nor ')' and nor
			operator */
			printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
			getchar();
			exit(1);
		}
		i++;


		item = infix[i]; /* go to next symbol of infix expression */
	} /* while loop ends here */
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
		getchar();
		exit(1);
	}

	postfix[j] = '\0'; /* add sentinel else puts() fucntion */
	/* will print entire postfix[] array upto SIZE */

}
int main() {
  printf("Enter the infix expression: ");
  scanf("%s",infix);
  infix_to_postfix();
  printf("%s",postfix);
  while(top>0) {
    printf("%c",stack[top--]);
  }
  printf("\n");
  return 0;
}
