#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1=m-l+1;
    int n2=r-m;

    //creating temporary arrays
    int L[n1], R[n2];

    //copy data to the temporary arrays
    for(i=0;i<n1;i++) 
        L[i]=arr[l+i];
    for(j=0;j<n2;j++)
        R[j]=arr[m+1+j];

    //merge the temp arrays back into the original array

    i=0; j=0; k=l;
    while(i<n1 && j<n2) {
        if(L[i]<=R[j]) {
            arr[k]=L[i];
            i++;
        }
        else {
            arr[k]=R[j];
            j++;
        }
        k++;
    }

    //copy the remaining elements
    while(i<n1) {
        arr[k]=L[i];
        i++;
        k++;
    }

    while(j<n2) {
        arr[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r) {
    if(l<r) {
        int m = (l+r-1)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[]={5,6,4,7,3,2,1,9,8,10};
    mergeSort(arr, 0, 9);
    for(int i=0;i<10;i++)
        printf("%d ", arr[i]);
    
    return 0;
}