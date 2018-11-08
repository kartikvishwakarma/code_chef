#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(int argc, char const *argv[])
{
	int T;
	ll N,a,b,sum;

	cin>>T;

	while(T--){
		map<ll,ll> minions;
		cin>>N;
		sum=0;
		for(int i=0; i<N;i++){
			cin>>a>>b;
			minions.insert(make_pair(a,b));
			sum+=b;
		}

		ll len = N;
		long double mean = ((long double)sum)/len;

		while((minions.begin()->first) < mean){
			ll num = minions.begin()->second;
			
			mean = ((mean*N)-num)/(N-1);
			N--;
			//cout<<mean<<" "<<N<<endl;
			minions.erase(minions.begin()->first);
		}
		cout<<N<<endl;

	}
	/* code */
	return 0;
}