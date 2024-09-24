//Sorting an array using Merge Sort
//Divide and Conquer Algorithm

#include <stdio.h>

void Merge(int arr[], int l, int mid, int r){
    int n1=mid-l+1, n2=r-mid;
    //dividing into two subarrays
    int a[n1], b[n2];
    for(int i=0; i<n1; i++) a[i] = arr[l+i];
    for(int i=0; i<n2; i++) b[i] = arr[mid+1+i];
    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++; i++;
        } else{
            arr[k]=b[j];
            k++; j++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        k++; i++;} 
    while(j<n2){
        arr[k]=b[j];
        k++; j++;
    }
}

void MergeSort(int arr[], int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        MergeSort(arr, l, mid);
        MergeSort(arr, mid+1, r);
        Merge(arr, l, mid, r);
    }
}

int main(){
    //user input array
    int n;
    printf("Enter length of array: "); 
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of the array: ");
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);

    //sorting array
    MergeSort(arr,0,n-1);
    
    //displaying sorted Array
    printf("Sorted Array: ");
    for(int i=0; i<n; i++) printf("%d ",arr[i]);

    return 0;
}