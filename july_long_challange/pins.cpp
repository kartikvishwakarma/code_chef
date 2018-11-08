#include <iostream>
#include <cmath>

using namespace std;
typedef unsigned long long ll;

const int size = (int)1e5+7;

int a[size],T,N;
ll q;

int main(){
	cin>>T;

	while(T--){
		cin>>N;
		if(N%2){
			q = (ll)(pow(10, (N-1)/2));
		} 
		else 
			q = (ll)(pow(10,N/2));

		cout<<1<<" "<<q<<"\n";
	}
}	