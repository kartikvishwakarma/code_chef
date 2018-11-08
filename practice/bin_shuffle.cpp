#include <iostream>

using namespace std;

typedef long long int ll;

int get_ones(ll x){
	int count=0;
	
	while(x){
		if(x%2)
			count++;
		x /=2;
	}

	return count;
}

int main(){
	int T, no_one_A, no_one_B,ans;
	ll A,B;

	cin>>T;

	while(T--){
		cin>>A>>B;
		
		//cout<<"A: "<<no_one_A<<"  B: "<<no_one_B<<endl;
		if (A==B)
			ans = 0;
		else if (B==0)
			ans = -1;
		
		else if(B==1){
			if(A==0)
				ans=1;
			else
				ans = -1;
		}
		else{
			no_one_A = get_ones(A);
			no_one_B = get_ones(B-1);
			if(no_one_A>no_one_B)
				ans = 2;
			else 
				ans = no_one_B - no_one_A +1;
		}
		cout<<ans<<endl;

	}
	return 0;
}