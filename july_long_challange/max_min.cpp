#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#define mod 1000000007
//#define p 1000000007
 
using namespace std;
typedef long long ll;
 

/* Iterative Function to calculate (x^y)%p
  in O(log y) */
ll power(ll x, ll y)
{
    ll res = 1;      // Initialize result
 
    x = x % mod;  // Update x if it is more than or
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % mod;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % mod;
    }
    return res;
}
 
// Returns n^(-1) mod p
ll modInverse(ll n)
{
    return power(n, mod-2);
}
 
// Returns nCr % p using Fermat's little
// theorem.
ll Cn(ll n, ll r)
{
   // Base case
   if (r==0)
      return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    ll fac[n+1];
    fac[0] = 1;
    for (ll i=1 ; i<=n; i++)
        fac[i] = fac[i-1]*i%mod;
 
    return (fac[n]* modInverse(fac[r]) % mod *
            modInverse(fac[n-r]) % mod) % mod;
}
int main(){
	int t,k,n;
	ll tmp,tmp1,tmp2;
	ll ans;
 
	cin>>t;
 
	while(t--){
		ans=1;
		cin>>n>>k;
		int a[n];
		vector<int> V[n+1];
 
		for(int i=1;i<=n;i++)
			cin>>a[i];
		
		sort(a+1,a+n+1);
		int p;
		for(int i=2; i<n;i++){
			int val = n-i;
			tmp=0;
			//cout<<i<<" | ";
			if(i<k)
				p=i;
			else 
				p=k-1;
			while(p>1 &&(k-p)+i<=n ){
				//cout<<p<<" ";
				//V[i].push_back(p);
				
				ll tmp1=Cn(i-1, p-1);
				ll tmp2=Cn(n-i,k-p);
				tmp+= (tmp1*tmp2)%mod;
				//cout<<tmp1<<" "<<tmp2<<"\n";
				cout<<tmp<<"\n";
				//printf("Cn(%d, %d) = %lld  Cn(%d, %d) = %lld  ",i-1,p-1,tmp1, n-i,k-p, tmp2 );
				//printf("(%d, %d) ",p,tmp);
				p--;
			}
		//printf("\n");
			//cout<<tmp<<"\n";
			
			if(tmp){
			//	cout<<a[i]<<" : "<<i<<" | ";
				ans=(ans%mod)*((ll)(power(a[i],tmp%mod))%mod);
			}
			
		}
		//cout<<"\n";
		//show(V,n);
		cout<<ans%mod<<"\n";
		//V.clear();
	}
} 