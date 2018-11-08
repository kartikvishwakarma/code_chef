#include <iostream>
//#include <cmath>
#include <iomanip>
using namespace std;
//typedef long long ll;

const int size = (int)1e5+7;

int a[size],T,N;
int q;

int main(){
	cin>>T;

	while(T--){
		cin>>N;
		if(N%2){
			q = (N-1)/2;
		} 
		else 
			q = N/2;

		cout<<1<<" "<<1;
		for(int i=1;i<=q;i++)
			cout<<"0";
		cout<<"\n";
	}
}	