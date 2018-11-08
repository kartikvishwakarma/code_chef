#include <iostream>

using namespace std;

int main(){
	int t,n,k;
	cin>>t;
	while(t--){
		cin>>n;
		int a[n+1];

		for(int i=1; i<=n; i++)
			cin>>a[i];

		for(int i=2; i<=n; i++){
			a[i] += a[i-1];
			//cout<<a[i]<<' ';
		}
		//cout<<'\n';

		int p=1;
		int day=1;
		while(a[p]<n){
			//cout<<p<<'\n';
			p = a[p+a[p]];
			day++;
		}
		cout<<day<<'\n';
	}
}