#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

typedef long long int ll;
int size = 10007;
ll M,L,R;
int N;

vector<pair<ll,ll> >range;
set<pair<ll,ll> > index;
ll Isinrange(ll n, ll diff, int N, ll M){

	bool flag= true;
	bool left, right;

	L = range[n].first;
	R = range[n].second;
	ll k=0;
	for(ll i = L;i<=R;i++){
			++k;
			flag = true;
		ll p = n;
		while(((++p)%N) != n){
		//for(ll p = 0; p<N;p++){
			//printf("alloll%lld\n", p);
			L = range[p].first;
			R = range[p].second;
			//cout<<i+diff<<" "<<L<<" "<<R<<"\n";
			left = ((p*k+diff)%M)>=L;
			right = ((p*k+diff)%M)<=R;

			if( left && right){
		//		printf("got it..\n");
				return diff;
			}
			else {
				flag = false;
				break;
			}

			//p++;
		}

		}
	return -1;
}


int main(int argc, char const *argv[])
{
	/* code */
	

	scanf("%lld%d",&M,&N);

	ll diff = ((ll)M)/N;

	for(int i=0;i<N;i++){
		scanf("%lld%lld", &L, &R);
		range.push_back(make_pair(L,R));
		index.insert(make_pair(abs(L-R), i));
	}

	//cout<<index.begin()->second<<"\n";
	ll min_inx = index.begin()->second;

	//cout<<L<<" "<<R<<"\n";
	while(Isinrange(min_inx,diff,N,M)<0 && diff){
		diff--;
	}

	printf("%lld\n", diff);
	
	return 0;
}