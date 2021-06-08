#include<bits/stdc++.h>
using namespace std;

bool isPossibleToPlaceStation(vector<int> gasStation,double distance,int k){
    int noOfGasStations = 0;
    for(int i = 1; i < gasStation.size(); i++){
        noOfGasStations += (gasStation[i] - gasStation[i - 1]) / distance;
        if(noOfGasStations > k) return true;
    }
    return false;
}
double getMaxDistance(vector<int> gasStation,int k){
    double si = 0.0, ei = 1e9;
    while((ei - si) > 1e-6){
        double distance = (si + ei) / 2.0;
        if(isPossibleToPlaceStation(gasStation,distance,k)){
            si = distance + 1e-6;
        }
        else{
            ei = distance;
        }
    }
    return si;
}
//minimize maximum distance to gas station
int main(){
    cout<<"enter size of array \n";
    int n;
    cin>>n;
    vector<int> gasStation;
    cout<<"\n Enter your gas stations : \n";
    for(int i = 0; i < n;i++){
        int val;
        cin>>val;
        gasStation.push_back(val);
    }
    cout<<"\n Enter number of extra stations \n";
    int k;
    cin>>k;
    cout<<"distance: ";
    cout<<getMaxDistance(gasStation,k);
    return 0;

}