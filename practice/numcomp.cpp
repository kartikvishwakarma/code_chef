#include <cstdio>
#include <cmath>
typedef long long int ll;

using namespace std;

int main(){
	int T;
	ll a,b,n;
	scanf("%d",&T);
		while(T--){
			scanf("%lld %lld %lld",&a,&b,&n);

			if(n%2){
				if(a>b){
					printf("1\n");
				}
				else if(a<b)
					printf("2\n");
				else 
					printf("0\n");
			}
			else{
				if(abs(a)>abs(b))
					printf("1\n");
				else if(abs(a)<abs(b))
					printf("2\n");
				else
					printf("0\n");
			}
		}
	return 0;
}