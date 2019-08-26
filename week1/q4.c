//
//  main.c
//  test
//
//  Created by Vignesh Srinivasan on 21/3/2018.
//  Copyright © 2018 Vignesh Srinivasan. All rights reserved.
//
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100;
int main() {
    int i,j,value,carry=0, index=0;;
    char num1[100], num2[100];
    printf("Enter the first number");
    scanf("%s",&num1);
    printf("Enter the second number");
    scanf("%s",&num2);
    int len1=strlen(num1);
    int len2=strlen(num2);
    
    int sum[101];
    
    //finding the sum
    for(i=len1-1,j=len2-1;i>=0 || j>=0;) {
        value=carry;
        if(i>=0) {
            value+=(num1[i]-'0');
            i--;
        }
        if(j>=0) {
            value+=(num2[j]-'0');
            j--;
        }
        
        sum[index]=(value%10)+'0';
        index++;
        carry=value/10;
    }
    if(carry)
        sum[index++]='1';
    
    for(int i=index-1;i>=0;i--) {
        printf("%c",sum[i]);
    }
}
