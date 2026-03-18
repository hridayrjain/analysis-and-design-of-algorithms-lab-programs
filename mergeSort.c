#include <stdio.h>
void merge(int arr[],int start,int mid,int end){
    int temp[end-start+1];
    int i=start,j=mid+1,k=0;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=end){
        temp[k++]=arr[j++];
    }
    for(int l=0;l<end-start+1;l++){
        arr[l+start]=temp[l];
    }
}
void mergeSort(int arr[],int start,int end){
    if(start>=end){
        return;
    }
    int mid=(start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,mid,end);
}
int main() {
    int n;
    printf("Enter the number of array elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    printf("Sorted array : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
