//Sorting an array using Selection Sort
//ALGORITHM: sort first element repeatedly--subarray

#include <stdio.h>

int main(){
    int n;  //user input array
    printf("Enter length of array: "); 
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of the array: ");
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);

    //sorting array
    for(int i=0; i<n; i++){ 
        int min = i;
        for(int j=i; j<n; j++){
            if(arr[j]<arr[min]) min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    
    //Sorted array
    printf("Sorted Array:\n"); 
    for(int i=0; i<n; i++) printf("%d ",arr[i]);

    return 0;
}
