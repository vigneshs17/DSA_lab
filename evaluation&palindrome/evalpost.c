#include <stdio.h>
#include <ctype.h>
#include <string.h>

int stack[100];
int top = -1;

int op(char op, int a, int b){
	switch(op){
		case '+' : return a + b;
		case '-' : return a - b;
		case '*' : return a * b;
		case '/' : return a / b;
	}
}

int main(void)
{
	char s[100];
	printf("Enter the string: ");
	scanf("%s", s);
	int l = strlen(s);
	int a[5], n;
	printf("Enter the number of values: ");
		scanf("%d", &n);
	printf("Enter the values: ");
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);


	for(int i = 0; i < l; i++)
	{
		if (isalnum(s[i])) {
			int m = s[i] - 'a';
			stack[++top] = (int)(a[m]) ;
		}
		else {
			int a1 = stack[top--];
			int a2 = stack[top--];
			int sum = op(s[i], a2, a1);
			stack[++top] = sum;
		}
	}
	if(top == 0)
		printf("%d\n", stack[top]);
	else
		printf("Invalid");

}
