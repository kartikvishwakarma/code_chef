#include <iostream>

using namespace std;

int main(){
	int t,n,k,p;

	cin>>t;

	while(t--){
		cin>>n>>k;

		for(int i=0; i<n;i++){
			cin>>p;

			if(p<=k){
				cout<<1;
				k -= p;
			}
			else
				cout<<0;
		}
		cout<<"\n";
	}
}