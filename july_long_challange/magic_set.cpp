#include <cstdio>
#include <cmath>
using namespace std;
typedef long long int ll;

void pow_set(int a[], int n, int m){
	ll size = (ll)pow(2,n);
	ll count=0;
	for(ll i=1;i<size-1; i++){
		ll p=0;
		for(ll j=0;j<=n;j++){
			if(i &(1<<j))
				p+=a[j];
		}
		if(p%m==0){
			//printf("%d : ", p);
			count++;
		}
	}

	printf("%lld\n", count);
}


int main(){
	int t,m,n;
	scanf("%d",&t);

	while(t--){
		scanf("%d%d",&n,&m);
		int a[n];

		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		pow_set(a,n,m);
	}
}