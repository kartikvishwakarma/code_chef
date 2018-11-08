#include <cstdio>
#include <cmath>
using namespace std;

typedef long long int ll;

const int size = (int)3e5+3;
ll a[size];
ll x[size];

int main(){
	int n,m;
	ll tmp,p=0;
	scanf("%d %d", &n,&m);

	for(int i=0; i<n;i++)
		scanf("%lld",&a[i]);

	for(int i=0;i<m; i++){
		scanf("%lld",&tmp);
		p=0;
		for(int i=n-1;i>=0;i--){
			if(tmp>a[i]){
				tmp=ceil(tmp/a[i]);
				p+=tmp;
			}
			else
				p+=1;
		}
		printf("%lld\n",p);
	}
	return 0;
}