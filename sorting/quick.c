#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

void swap(int *a, int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}

void quickSort(int arr[], int low, int high) {
    if(low<high) {
        int pi=partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot=arr[high];
    int i=low-1;

    for(int j=low;j<=high-1;j++) {
        if(arr[j]<pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return i+1;
}

int main() {
    int arr[]={5,6,4,7,3,2,1,9,8,10};
    quickSort(arr, 0, 9);
    for(int i=0;i<10;i++)
        printf("%d ", arr[i]);
    
    return 0;
}