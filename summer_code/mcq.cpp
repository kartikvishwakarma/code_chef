#include <iostream>
#define mod 1000000007

using namespace std;

typedef long int li;

li power(li k, li n){
	if(n==0)
		return 1;
	if(n==1)
		return k%mod;


	if (k==1)
		return 1;
	else if (k==0)
		return 0;
	else if(n%2 == 0){
		
		li ans = power(k,n/2);
		ans = (ans*ans)%mod;
		//cout<<"even : "<<ans<<"\n";
		ans = ((k*(ans-1))%mod)/(k-1);
		return ans;
	}
	else{
		li ans = power(k,n/2);
		//cout<<ans;
		ans = (ans*ans)%mod;
		ans = (ans*k)%mod;
		//cout<<"odd : "<<ans<<"\n";
		ans = ((k*(ans-1))%mod)/(k-1);
		return ans;	
	}
	return -1;
}

int main(){
	li t,n,k;
	li ans;
	cin>>t;

	while(t--){
		//ans=0;
		cin>>n>>k;
		ans = power(k,n);
		cout<<ans<<"\n";
	}
}