#include<stdio.h>
#include<math.h>

int main() {
	long int n;
	int i=0;
	float low, middle, high;
	printf("Enter the number: ");
	scanf("%ld",&n);
	low=0;
	high=n;
	middle=(low+high)/2;
	while(1) {
		middle=(low+high)/2; 
		if(fabs(pow(middle,2)-n)<0.001) {
			printf("%.4f is the square root of %ld", middle, n);
			break; 
		}
		else if(pow(middle,2)>n) 
			high=middle;
		else if(pow(middle,2)<n) 
			low=middle;
		else 	
			printf("Square root exist");
		i++;
	}
	return 0;
}
				
