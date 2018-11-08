#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <assert.h>

using namespace std;

int debug;
int N;
int answer;
int total_queries;

map<int, int> mp;

int ask(int where){
	if(mp.find(where) != mp.end())
		return mp[where];

	total_queries++;

	assert(where>=1 && where <=N);
	printf("%d %d\n",1, where);
	fflush(stdout);
	int value;
	scanf("%d", &value);

	if(debug)
		cerr<<"value at "<<where<<" received "<<value<<endl;

	mp[where] = value;

	return value;  
}

void tell(int answer){
	total_queries++;
	if(debug)
		cerr<<"answer is: "<<answer<<endl;
	printf("%d %d\n",2, answer);

	fflush(stdout);
}

int find_K(){
	int start = ask(1);
	int pos_K = 1;
	int l = 1;
	int r = N;
	
	while(l<=r){
		int mid = l + (r-l)/2;
		int val = ask(mid);
		if(val == start)
			pos_K = mid;
		if(val > start)
			r = mid-1;
		else
			l = mid+1;
	}

	if(debug)
		cerr<<"pos_K: "<<pos_K<<endl;

	if(2*pos_K > N)
		answer = ask(pos_K+1);

	else{
		if(ask(2*pos_K) == ask(2*pos_K+1)){
			if(ask(N) != ask(N - pos_K))
				answer = ask(pos_K+1);
			else answer = start;
		}
		else
			return pos_K;
	}
	return -1;
}

int solve(int K){
	assert(N%K != 0);
	int l = 1, r = N/K;
	int pos = N;
	while(l<=r){
		int mid = l + (r-l)/2;
		if(ask(K*mid) == ask(K*mid+1)){
			r = mid-1;
			pos = K*(mid-1) + 1;
		}
		else
			l = mid+1;
	}
	if(debug)
		cerr<<"pos: "<<pos<<endl;
	return ask(pos);
}

int main(){
	vector <int> Ns {78776, 82861, 1560, 37989, 12258, 3141, 83769};

	int T;
	scanf("%d", &T);
	cerr <<T<<endl;

	int max_queries = 0;
	int whichN = -1;

	while(T--){
		scanf("%d", &N);
		debug=false;
		for(int i=0; i<Ns.size(); i++){
			if(Ns[i] == N)
				debug = false;
		}

		total_queries = 0;
		mp.clear();
		answer = -1;

		int K = find_K();

		if(debug)
			cerr<<"K "<<K<<endl;

		if(answer == -1)
			answer = solve(K);

		tell(answer);

		if(total_queries>max_queries || (total_queries == max_queries && N > whichN)){
			max_queries = total_queries;
			whichN = N;
		}

		max_queries = max(max_queries, total_queries);
	}

	cerr<<"Max Queries: "<<max_queries<<endl;
	cerr<<"whichN: "<<whichN<<endl;

	return 0;
}