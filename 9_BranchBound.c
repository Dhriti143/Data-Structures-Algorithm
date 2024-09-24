#include <stdio.h>
#include <limits.h>

#define maxCities 50

int cities; //total no of cities
int cost[maxCities][maxCities]; //cost of travelling between two cities
int visited[maxCities]; //cities visited
int trip[maxCities]; //best route found
int leastCost = INT_MAX; //minimum cost of route travelled

void tsp(int currentCity, int visitedCount, int route[], int totalCost){

    if(visitedCount==cities && cost[currentCity][0]>0){
        //all cities are covered and adding final cost of returning to starting city
        totalCost+=cost[currentCity][0];
        if (totalCost < leastCost) { 
            //better route found, update cost and route of travelling
            leastCost = totalCost;
            for (int i = 0; i < cities; i++) {
                trip[i] = route[i];
            }
        }
        return;
    }
 
    if(totalCost>=leastCost){
        //cost is not minimzed than alreaddy found route then return
        return;
    }
 
    for(int i=0; i<cities; i++){
        if(!visited[i] && cost[currentCity][i]>0){
            //visting a new city
            visited[i] = 1;
            route[visitedCount] = i;
            tsp(i,visitedCount+1,route,totalCost+cost[currentCity][i]); //exploring remaining cities from this city
            visited[i] = 0; //backtracking - unmark visited city
        }
    }
}

int main(){
    //user input
    printf("No. of cities(up to %d): ", maxCities);
    scanf("%d", &cities);
    printf("City to City travelling cost(matrix form):\n");
    for (int i = 0; i < cities; i++) {
        for (int j = 0; j < cities; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    
    visited[0]=1; //starting from the first city and marking it as visited
    int route[maxCities];
    route[0] = 0; //storing path while exploring
    tsp(0,1,route,0);
    
    printf("\nPath: "); //displaying result
    for(int i=0; i<cities; i++){
        printf(" %d ->",trip[i]);
    }
    printf(" 0\n");
    printf("Cost=%d",leastCost);
    return 0;
}
