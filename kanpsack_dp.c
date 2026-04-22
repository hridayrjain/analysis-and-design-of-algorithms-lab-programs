#include<stdio.h>
int max(int a,int b){
    if(a>=b) return a;
    return b;
}
int main(){
    int n,m;
    printf("Enter the number of items.\n");
    scanf("%d",&n);
    printf("Enter the knapsack capacity.\n");
    scanf("%d",&m);
    int w[n+1],v[n+1];
    printf("Enter the weight and value of the items.\n");
    for(int i=1;i<=n;i++){
        scanf("%d%d",&w[i],&v[i]);
    }
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j<w[i]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j], v[i]+dp[i-1][j-w[i]]);
            }
        }
    }
    printf("The maximum possible profit is %d .\n",dp[n][m]);
    return 0;
}
