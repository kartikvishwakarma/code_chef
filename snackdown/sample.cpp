#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
	int ar [] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};

	int n = sizeof(ar)/sizeof(ar[1]);
	int size = (n*(n-1))/2;
	int prod[size] ;
	int p=0;
	for(int i=0; i<n;i++){
		for(int j=i+1; j<n;j++){
			//cout<<(ar[i]*ar[j])<<' ';
			prod[p++] = (ar[i]*ar[j]);
		}
	} 
	set<int> v;

	for(int i=0; i<size; i++){
		for(int j=i;j<size; j++){
			//cout<<(prod[i]+prod[j])<<' ';
			v.insert(prod[i]+prod[j]);
		}
	}
	int t;
	cin>>t;
/*
	for(auto l : v)
		cout<<l<<' ';
	cout<<'\n';*/
	
	while(t--){
		cin>>n;
		if(v.find(n) == v.end())
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
}