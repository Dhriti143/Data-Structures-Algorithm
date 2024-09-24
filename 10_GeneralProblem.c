//N License problem using Greedy Approach
#include <stdio.h>
#include <limits.h>

#define N 50
int purchase[N]; //storing the license number in order of purchase

void calculateOrder(int rate[], int l){
    int max = 0, index, r[l];
    for(int i=0; i<l; i++) r[i] = rate[i];
    for(int i=0; i<l; i++){
        for(int j=0; j<l; j++){
            if(r[j]>max) {
                max=r[j];
                index = j;
            }
        }
        purchase[i]=index;
        r[index] = 0;
        max=0; index=0;
    }
}

int calculateCost(int order[], int rate[], int l){
    int cost = 0;
    for(int i=0; i<l; i++){
        if(i==0){ cost+=100; }
        else{
            int factor = rate[order[i]];
            cost = cost + (100*factor*i);
        }
    }
    return cost;
}

int main()
{
    //user input
    int l; //Total no license to be bought
    printf("No. of license: ");
    scanf("%d",&l);

    int rate[l];//rate of growth of each license
    printf("Rate of price growth: ");
    for(int i=0; i<l; i++) {
        scanf("%d",&rate[i]);
    }

    //calulation
    for(int i=0; i<l; i++){ //updating with respect to license number
        rate[i]=rate[i]*(i+1);
    }

    calculateOrder(rate, l);
    int cost = calculateCost(purchase, rate, l);

    // displaying result
    printf("License no. in order of purchase: ");
    for(int i=0; i<l; i++) {
        printf("%d ",purchase[i]);
    }
    printf("\nTotal Cost: $%d ",cost);

    return 0;
}
