#include<bits/stdc++.h>
using namespace std;
int foursumcount(vector<int>& arr1,vector<int>& arr2,vector<int>& arr3,vector<int>& arr4){
    unordered_map<int,int> mp;
    for(int e1 : arr1){
        for(int e2 : arr2){
            mp[e1 + e2]++;
        }
    }
    int count = 0;
    for(int e1 : arr3){
        for(int e2 : arr4){
            if(mp.find(0 - (e1 + e2)) != mp.end()){
                count += mp[0 - (e1 + e2)];
            }
        }
    }
    return count;
}
int main(){
    vector<int> arr1,arr2,arr3,arr4;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int val;
        cin>>val;
        arr1.push_back(val);
    }
    for(int i = 0; i < n; i++){
        int val;
        cin>>val;
        arr2.push_back(val);
    }
    for(int i = 0; i < n; i++){
        int val;
        cin>>val;
        arr3.push_back(val);
    }
    for(int i = 0; i < n; i++){
        int val;
        cin>>val;
        arr4.push_back(val);
    }

    cout<<foursumcount(arr1,arr2,arr3,arr4);
    return 0;
}