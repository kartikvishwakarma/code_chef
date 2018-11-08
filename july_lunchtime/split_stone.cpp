#include <iostream>

using namespace std;

int main(){
	int t,a,b,c,x,y;

	cin>>t;

	while(t--){
		cin>>a>>b>>c>>x>>y;
		int M = max(x,y);
		if((a+b+c)==(x+y)){
			if(M>(a+b) && M>(a+c) && M>(b+c))
				cout<<"NO\n";
			else 
				cout<<"YES\n";
		}
		else 
			cout<<"NO\n";

	}
return 0;
}