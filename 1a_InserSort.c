//Sorting an array using Insert Sort
//ALGORITHM: similar to sorting of cards in hands. 

#include <stdio.h>

int main(){
    //user input array
    int n;
    printf("Enter length of array: "); 
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of the array: ");
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);

    //sorting array
    for(int i=1; i<n; i++){ 
        int x = arr[i];
        int j = i-1;
        while(arr[j]>x && j>=0){
            arr[j+1]= arr[j];
            j--;
        }
        arr[j+1] = x;
    }
    
    //Sorted Array
    printf("Sorted Array:\n");
    for(int i=0; i<n; i++) printf("%d ",arr[i]);

    return 0;
}

