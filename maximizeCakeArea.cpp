#include<bits/stdc++.h>
#define M_PI 3.14159265358979323846
using namespace std;
bool isPossibleToServe(vector<int>&radii,int guests,double cakeArea){
    int g = 0;
    for(int i = radii.size() - 1; i >=0; i--){
        double area = M_PI * radii[i] * radii[i];
        g += floor(area/cakeArea);
        if(g >= guests) return true;
    }
    return false;
}
double getCakeArea(vector<int>& radii,int guests){
    sort(radii.begin(),radii.end());
    int n = radii.size();
    // double si = M_PI * radii[0] * radii[0], ei = M_PI* radii[n - 1]* radii[n - 1];
    double si = 0.0, ei = 1e6;
    while((ei - si) > 1e-5){
        double cakeArea = (si + ei) / 2.0;
        if(!isPossibleToServe(radii,guests,cakeArea)){
            ei = cakeArea - 1e-5;
        }
        else si = cakeArea;
    }
    return si;

}
int main(){
    cout<<"enter size of array \n";
    int n;
    cin>>n;
    vector<int> radii;
    cout<<"\n Enter your radii : \n";
    for(int i = 0; i < n;i++){
        int val;
        cin>>val;
        radii.push_back(val);
    }
    cout<<"\n Enter number of guests \n";
    int guests;
    cin>>guests;
    cout<<"Maximum Area Served to Guests : ";
    cout<<getCakeArea(radii,guests);
    return 0;

}