#include <stdio.h>

int main() {
    int cost[10][10],visited[10]={0};
    int n,i,j,ne=1;
    int min,a,b,u,v,mincost=0;

    printf("Enter the number of vertices:\n");
    scanf("%d",&n);

    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0) {
                cost[i][j]=999;
            }
        }
    }

    visited[0]=1;

    printf("The edges of Minimum Spanning Tree are:\n");
    while(ne<n) {
        min=999;
        for(i=0;i<n;i++) {
            if(visited[i]) {
                for(j=0;j<n;j++) {
                    if(!visited[j]&&cost[i][j]<min) {
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }

        if(!visited[v]) {
            ne++;
            printf("%d -> %d = %d\n",a,b,min);
            mincost+=min;
            visited[v]=1;
        }

        cost[a][b]=cost[b][a]=999;
    }

    printf("Minimum cost=%d\n",mincost);
    return 0;
}
