//Solving N queens problem using Backtracking
#include <stdio.h>
#define N 3


int check(int s[N][N], int row, int column){
    int i, j;
    //check for row
    for(i=column-1;i>=0;i--){
        if(s[row][i]==1){
            return 0;
        }
    }
    //check for diagonally upwards
    for(i=row,j=column; i>=0&&j>=0; i--,j--){
        if(s[i][j]==1){
            return 0;
        }
    }
    //check for diagonally downwards
    for(i=row,j=column; i<=N&&j>=0; i++,j--){
        if(s[i][j]==1){
            return 0;
        }
    }
    return 1;
}

int placeQueen(int s[N][N], int column){
    if (column>=N) return 1;
    for(int i=0;i<N;i++){
        if(check(s,i,column)){
            s[i][column]=1;
            if(placeQueen(s,column+1)){
                return 1;
            }
            s[i][column]=0;
        }
    }
    return 0;
}

int main(){
    int s[N][N] = {0}; 
    
    if(placeQueen(s,0)){
        for(int i=0;i<N; i++){
            for(int j=0; j<N; j++){
                if(s[i][j]){
                    printf("Q ");
                }
                else{
                    printf("- ");
                }
            }
            printf("\n");
        }
    }
    else{
        printf("Solution doesn't exist");
    }
    return 0;
}
