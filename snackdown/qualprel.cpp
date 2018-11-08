#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
	int t,n,k,r;

	cin>>t;
	while(t--){
		cin>>n>>k;
		vector<int> v;
		int a[n];
		for(int i=0; i<n; i++){
			cin>>a[i];
		}

		sort(a, a+n, greater<int>());

		int r = a[k-1];

		int i=1, count=0;
		while(i<n && a[i]>=r){
			i++;
		}

		cout<<i<<'\n';
	}
}