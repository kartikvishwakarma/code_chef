#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <utility>
#include <tuple>
#include <set>

using namespace std;

typedef long long ll;
const int size = (int)1e5 + 7;

int T,M,N, zombies[size];
ll D[size];
vector< pair<int, int> > c[size];

int main(){
	
	cin>>T;

	while(T--){
		cin>>N>>M;

		for(int i=1; i<=N; i++)
			cin>>zombies[i];

		for(int i=1; i<=M; i++){
			int L,R,K;
			cin>>L>>R>>K;
			c[L].push_back(make_pair(R,K));
		}

		set< pair<int, int> >s;
		ll dmg = 0, ans = 0;
		for(int i = 1; i<=N; i++){
			dmg -= D[i];

			for(int j=0; j<c[i].size(); j++) 
				s.insert(c[i][j]);
			zombies[i] -= dmg;

			while(zombies[i]>0){
				if(s.empty() || s.rbegin()->first < i){
					ans = -1; 
					break;
				}
				//cout<<"here..\n";
				 int R, K;
				 tie(R,K) = *s.rbegin();
				 s.erase(prev(s.end()));

				 int d = min(zombies[i],K);
				 zombies[i] -= d;
				 K -= d;
				 ans += d; dmg += d;
				 D[R+1] += d;

				 if(K)
				 	s.insert(make_pair(R,K));
			}
			if(ans == -1)
				break;
		}
		if(ans == -1)
			cout<<"NO\n";
		else 
			cout<<"YES "<<ans<<"\n";

		fill_n(D+1, N, 0);
		fill_n(c+1, N, vector<pair<int, int> >(0));
	}

	return 0;
} 