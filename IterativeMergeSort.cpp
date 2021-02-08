#include<bits/stdc++.h>
using namespace std;


void merge(int arr[], int low, int mid, int high){
    int temp[100];
    int i=low,j=mid+1,k=low;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    for(;i<=mid;i++){
        temp[k++]=arr[i];
    }
     for(;j<=high;j++){
        temp[k++]=arr[j];
    }

    for(int i=low;i<=high;i++){
        arr[i]=temp[i];
    }
}

void IterativeMergeSort(int arr[], int n){
    int p, low,mid,high;
    for(p=2;p<=n;p=p*2){
        for(int i=0;i+p-1<n;i+=p){
            low=i;
            high=i+p-1;
            mid=(low+high)/2;
            merge(arr,low,mid,high);
        }
    }
    if(p/2<n){
        merge(arr,0,p/2,n-1);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements in your array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    IterativeMergeSort(arr,n);

    cout<<" After MergeSort Arr = [ ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" , ";
    }
    cout<<" ] ";

    return 0;
}