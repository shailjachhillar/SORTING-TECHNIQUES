#include<bits/stdc++.h>
using namespace std;

int partition(int A[],int s,int e)
{
	int pivot=A[s];
	int i=s,j=e;
	while(i<j){
		while(A[i]<=pivot){
			i++;
		}
		while(A[j]>pivot){
			j--;
		}
		if(i<j)swap(A[i],A[j]);
	}
	swap(A[s],A[j]);
	return j;
	// do
	// {
// do{i++;}while(A[i]<=pivot);
// do{j--;}while(A[j]>pivot);
//
// if(i<j)swap(&A[i],&A[j]);
// }while(i<j);
//
// swap(&A[l],&A[j]);
// return j;
}
void QuickSort(int A[],int s,int e)
{
	int p;
	
	if(s<e)
	{
		p=partition(A,s,e);
		QuickSort(A,s,p);
		QuickSort(A,p+1,e);
		 }
}
int main()
{
	int n;
	cout<<"Enter the size of your array \n";
	cin>>n;
	int arr[n];
	cout<<"\n Enter your array \n";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	cout<<"\n A = [";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" , ";
	}
	cout<<"] ";
	
	QuickSort(arr,0,n);
	
	cout<<"\nAfter QuickSort A = [";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" , ";
	}
	cout<<"] ";
	

 return 0;
}
