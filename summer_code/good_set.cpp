#include <iostream>
#include <algorithm>

using namespace std;

bool isGoodset(int a[], int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1; j<n;j++){
			if(__gcd(a[i],a[j])==1){
				return true;
				
			}
		}
	}
	return false;
}

int main(){
	int n,t;
	bool flag;
	cin>>t;

	while(t--){
		cin>>n;
		int a[n];
		flag=false;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]==1)
				flag=true;
		}

		if(flag)
			cout<<"YES\n";
		else{
			bool r = isGoodset(a,n);
			if(r)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}

	}
}