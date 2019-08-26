//
//  main.c
//  Circular number
//
//  Created by Vignesh  Srinivasan on 29/5/2019.
//  Copyright © 2019 Vignesh Srinivasan. All rights reserved.
//

#include <stdio.h>

int main() {
    
    int arr[100], digit, carry=0, n, product, i=0, len;
    printf("Enter n:");
    scanf("%d",&n);
    
    while(!(carry==0 && arr[i]==n)) {
        arr[0]=n;
        product=n*arr[i]+carry;
        digit=product%10;
        carry=product/10;
        arr[i+1]=digit;
        i++;
    }
    len=i;
    for(int i=len-1;i>0;i--) 
        printf("%d",arr[i]);
    printf("%d", n);
    return 0;
}
