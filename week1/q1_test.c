//longest increasing subsequence

#include<stdio.h>

int _lis(int arr[], int n, int* max_ref)
{
    
    if (n == 1)
        return 1;
    
    int res, max_ending_here = 1;
    
    
    for (int i = 1; i < n; i++) {
        res = _lis(arr, i, max_ref);
        if (arr[i - 1] < arr[n - 1] && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }
    
    if (*max_ref < max_ending_here)
        *max_ref = max_ending_here;
    
   
    return max_ending_here;
}


int lis(int arr[], int n)
{
    
    int max = 1;
    
    _lis(arr, n, &max);
    
    return max;
}

int main()
{
    int n,max=1;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    printf("%d\n",lis(arr, n));
    return 0;
}

