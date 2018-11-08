#include <iostream>
#include <algorithm>

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
typedef long long ll;
int main(){
	int T;
	ll A,B,X;

	cin>>T;

	while(T--){
		cin>>A>>B;

		ll l=1;
		ll r = B;
		

		while(l<r){
			ll mid = (l+r)>>1;
			cout<<l<<" "<<r<<"\n";
			if (A*B*mid < A*B*r && A*B*mid > A*B*l)
				break;

			else if(A*B*mid > A*B*l)
				l = mid+1;

			else if(A*B*mid < A*B*r)
				r = mid-1;
		}
		cout<<l<<"\n";
	}
}