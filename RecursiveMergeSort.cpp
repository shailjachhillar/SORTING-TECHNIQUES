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

void RecursiveMergeSort(int arr[], int low, int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        RecursiveMergeSort(arr,low,mid);
        RecursiveMergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);

    }

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    cout<<" Enter "<<n<<" elements in your array \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    RecursiveMergeSort(arr,0,n-1);
    cout<<" After Merge Sort A = [ " ;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" , ";
    }
    cout<<" ] ";
    return 0;
}