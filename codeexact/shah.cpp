#include <iostream>

using namespace std;
typedef long long ll;
const ll N = (ll)(1e+8);
ll dp[N+2];
/*
int solve(int n, int k){
	if(n==1){
		//cout<<n<<" "<<k<<"\n";
		return n;
	}
	else
		return (solve(n-1,k)+k-1)%n+1; 
}
*/
int dp_solve(ll n, ll k){
	
	//cout<<"here\n";
	for(ll i=1;i<=n;i++){
		if(i==1 || i==2)
			dp[i]=i;
		else
			dp[i]=(dp[i-1]+k-1)%i+1;
	//	cout<<"there\n";
	}
	//cout<<dp[n-1]<<" "<<dp[n]<<"\n";
}

int main(){
	ll t, n;
	dp_solve(N,2);
	//cout<<"done\n";
	cin>>t;
	while(t--){
		cin>>n;
		cout<<dp[n-1]<<" "<<dp[n]<<"\n";
	}
}