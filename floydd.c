#include <stdio.h>
#define INF 9999
int min(int a,int b){
    if(a<=b) return a;
    return b;
}
int main(){
    int n;
    printf("Enter the number of vertices.\n");
    scanf("%d",&n);
    int w[n][n];
    printf("Enter the adjacency matrix.\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&w[i][j]);
            if(w[i][j]==0 && i!=j){
                w[i][j]=INF;
            }
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                w[i][j]=min(w[i][k]+w[k][j],w[i][j]);
            }
        }
    }

    printf("\nFinal distance Matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",w[i][j]);
        }
        printf("\n");
    }
}
