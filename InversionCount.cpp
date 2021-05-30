#include<bits/stdc++.h>
using namespace std;
long long inversionAcrossArray(vector<long long>& arr, int l, int r, int mid,vector<long long> sortedArray){
    int lsi = l,lei = mid;
    int rsi = mid + 1, rei = r;
    long count = 0;
    int k = 0;
    while(lsi <= lei && rsi <= rei){
        if(arr[lsi] > arr[rsi]){
            count += (lei - lsi + 1);
            sortedArray[k++] = arr[rsi++];
        }else{
            sortedArray[k++] = arr[lsi++];
        }
    }

    while(lsi <= lei) sortedArray[k++] = arr[lsi++];
    while(rsi <= rei) sortedArray[k++] = arr[rsi++];
    k = 0;
    for(int i = l; i <= r;i++){
        arr[i] = sortedArray[k++];
    }
    return count;
}
long long inversionCount(vector<long long>& arr, int si, int ei,vector<long long>& sortedArray){
    if(si >= ei) return 0;
    int mid = (si + ei) / 2;
    long icl = inversionCount(arr,si,mid,sortedArray);
    long icr = inversionCount(arr,mid + 1,ei,sortedArray);

    return (icl + icr + inversionAcrossArray(arr,si,ei,mid,sortedArray));
}

long long inversionCount(long long ar[],long N){
    if(N <= 1) return 0;
    vector<long long> arr;
    for(int i = 0; i < N;i++){
        arr.push_back(ar[i]);
    }
    vector<long long> sortedArray(N,0);
    
    return inversionCount(arr,0,(int)N - 1,sortedArray);
}
int main(){
    long long n;
    cin>>n;
    long long ar[n];
    for(long long i= 0 ; i < n;i++){
        cin>>ar[i];
    }
    cout<<inversionCount(ar,n);
    return 0;
}
