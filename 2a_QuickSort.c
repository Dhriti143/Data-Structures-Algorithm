//Sorting an array using Quick Sort
//Divide and Conquer Algorithm

#include <stdio.h>

void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j]; 
    a[j] = temp;
}

int partition(int arr[], int l, int r){
    int pivot = arr[r], i = l-1;
    for(int j=l; j<r; j++){
        if(arr[j]<pivot){
            i++; 
            swap(arr,i,j);
        }
    }  
    swap(arr,i+1,r);
    return i+1;
}

void quickSort(int a[], int l, int r){
    if(l<r){
        int p = partition(a,l,r);
        quickSort(a, l, p-1);    
        quickSort(a, p+1, r);
    }
}

int main(){
    //user input array
    printf("Enter length of array: "); 
    int n; scanf("%d", &n);
    int arr[n];
    printf("Enter elements of the array: ");
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    
    //sorting array
    quickSort(arr,0,n-1);
    
    printf("Sorted Array: \n");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);

    return 0;
}
