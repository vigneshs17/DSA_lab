// find the index of the word in the dictionary

#include <stdio.h>
#include<string.h>
#include <math.h>

void printPowerSet(char *set, int set_size)
{
    
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;
	char dict[pow_set_size];
   
    for(counter = 0; counter < pow_set_size; counter++)
    {
	char string[20];
        for(j = 0; j < set_size; j++)
        {
            if(counter & (1<<j))
                printf("%c",set[j]);
        }
//	printf("%s", string);
        printf("\n");
    }

    char search[20];
    int result, len, value,i;
    printf("Enter the seach to be searched:");
    scanf("%s",&search);
    len=strlen(search);
    for(i=len-1,j=0;i>=0,j<len;i--,j++) {
	value+=pow(26,i)*(search[j]-'a');
	}
    printf("value=%d",value);
    for(int i=0;i<set_size;i++) {
        result=strcmp(search,set[i]);
        if(result==0) {
            printf("if %d",i);
        }
        else
            printf("else %d",i);
            continue;
    }
    
}

/*Driver program to test printPowerSet*/
int main()
{
    char set[] = {'a','b','c'};
    printPowerSet(set, 3);
    return 0;
}


