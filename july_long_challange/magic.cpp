#include <cstdio>
#include <cmath>
//#include <unordered_map>
#include <string>
using namespace std;
typedef long long int ll;

void pow_set(int a[],int n,int m){
	//unordered_map<int,int> map;
	int p=0;
	for(int i=0;i<n;i++){
		if(a[i]%m==0)
			p++;
	}

	ll ans = (ll)pow(2,p)-1;

	printf("%lld\n", ans);
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