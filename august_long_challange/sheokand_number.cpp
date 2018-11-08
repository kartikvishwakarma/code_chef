#include <iostream>
#include <cmath>

using namespace std; 

int main(){
	int n,t,val;

	cin>>t;

	while(t--){
		cin>>n;

		int l = (int)(log2(n));
		int res = n-pow(2,l);
		if(res){
			int r = (int)log2(res);
			int ans = res-pow(2,r);

			if(ans){
				val = min(res-pow(2,r-1), pow(2,r+1)-res);
				cout<<val<<"\n";
			}
			else
				cout<<"0\n";
		}
		else{
			//val = min(res-pow(2,l-1), pow(2,l+1)-res);
			cout<<"1\n";			
		}
	}
}