#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

typedef long long ll;

map<pair<int, int>, ll> nCr;


ll Cn(ll n, ll k)
{
	if (n<1 || k<1)
		return 1;

    ll Fn = 1, Fk, Fc;
    
    // Compute n! and (n-k)!
    for (ll i = 1; i <= n; i++)
    {
        Fn = ((Fn%mod)*i)%mod;
        if ((n-k)==0)
        	Fk=1;

        else if (i == n - k)
            Fk = Fn%mod;
        if(k==0)
        	Fc=1;
        else if (i==k)
            Fc=Fn%mod;
    }

    ll coeff = ((Fn%mod) / ((Fk*Fc)%mod))%mod;
    return coeff;
}

int main(){
	ll ans;
	int n = 5000;
	for(int i=0;i<=n; i++){
		for(int j=0;j<=i;j++){
			ans = Cn(i,j);
			nCr[{i,j}]=ans;
		}
	}

	
	for(int i=0;i<=n; i++){
		for(int j=0;j<=i;j++){
			cout<<nCr[{n,i}]<<" ";
		}
		cout<<"\n";
	}

}