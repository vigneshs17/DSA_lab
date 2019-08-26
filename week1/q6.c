#include<stdio.h>
#include<math.h>
int main() {
	int n;
	printf("Enter the number: ");
	scanf("%d",&n);
	for(int i=0;i<1000000;i++) {
		if(n<pow(2,i)) {
			printf("%d bits are required to store the number %d",i-1,n);
			break;
		}
	}
	return 0;
}
