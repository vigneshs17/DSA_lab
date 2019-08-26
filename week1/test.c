#include<stdio.h>
#include<math.h>
int main() {
    	int n, index;
   	printf("Enter the value of n:");
    	scanf("%d",&n);
	printf("n=%d",n);
	char arr[n],str[n];
	printf("Enter the alphabets:");
    	for(int i=0;i<2*n;i++) { 
		scanf("%c",&arr[i]);
	}
	//searching
	printf("Enter the word to be searched: ");
	scanf("%s",&str);
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			printf("str[i]=%c arr[i]=%c",str[i],arr[i]);
			index+=(str[i]-arr[i][j])*pow(2,n-1-i);
		}
	}
	printf("index=%d",index);
	return 0;
}
