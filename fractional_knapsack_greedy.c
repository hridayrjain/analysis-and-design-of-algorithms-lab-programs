# include <stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int n,m;
    printf("Enter the number of items.\n");
    scanf("%d",&n);
    int p[n],w[n];
    float x[n];
    printf("Enter the profit and weight for each item.\n");
    for(int i=0;i<n;i++){
        scanf("%d%d",&p[i],&w[i]);
        x[i]=p[i]*1.0/w[i];
    }
    printf("Enter the knapsack capacity.\n");
    scanf("%d",&m);
    for(int i=0;i<n-1;i++){
        for(int j=1;j<n-i;j++){
            if(x[j]>x[j-1]){
                float temp=x[j];
                x[j]=x[j-1];
                x[j-1]=temp;
                swap(&w[j],&w[j-1]);
                swap(&p[j],&p[j-1]);
            }
        }
    }
    float profit=0;
    int i;
    for(i=0;i<n;i++){
        if(w[i]>m){
            break;
        }else{
            profit+=p[i];
            m-=w[i];
        }
    }
    if(i<n){
        profit+=(x[i]*m);
    }
    printf("The maximum possible profit is %.2f ",profit);
    return 0;
}
