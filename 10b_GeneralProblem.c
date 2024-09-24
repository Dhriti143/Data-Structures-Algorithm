// Finding peak value using divide and conquer
#include <stdio.h>

int peak(int arr[], int n){
    int l = 0, h = n-1, mid;
    while (l<h)
    {
        mid = (l+h)/2;
        if (arr[mid]<arr[mid+1])
        {
            l = mid+1;
        } else
        {
            h = mid;
        }
    }
    return l;
}


int main(){
    //user input
    int n;
    printf("No. of elements: "); scanf("%d",&n);
    int arr[n];
    printf("Enter Elements: ");
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);

    //finding peak value
    int p = peak(arr, n);

    //displaying result
    printf("Peak Value: %d",arr[p]);

    return 0;
}
