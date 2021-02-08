#include<bits/stdc++.h>
using namespace std;
void CountSort(int arr[],int n){
    int max=*max_element(arr, arr + n);
    int *c;
    c=new int[max+1];
    for(int i=0;i<max+1;i++){
        c[i]=0;
    }
    for(int i=0;i<n;i++){
        c[arr[i]]++;
    }

    int i=0,j=0;
    while(i<max+1){
        if(c[i]>0){
            arr[j++]=i;
            c[i]--;
        }
        else{
            i++;
        }
    }
    
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    cout<<" Enter "<< n << " elements in your array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    CountSort(arr,n);
    cout<<" After CountSort A = [ ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" , ";
    }
    cout<<" ] ";
    return 0;
}