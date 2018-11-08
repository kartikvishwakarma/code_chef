#include <cstdio>
#include <algorithm>
#include <cassert>

using namespace std;

const int size = (int)1e5 + 5;

typedef long long int ll;
int min_arr[size], max_arr[size], perm_arr[size];
ll min_sum, max_sum,ans;


int main(){
	int T,N;
	ll K;
	scanf("%d",&T);

	while(T--){
		scanf("%d %lld", &N, &K);

		for(int i=0; i<N;i++)
			min_arr[i] = i+1;

		int d = N;
		for(int i=1; i<N;i+=2)
			max_arr[i] = d--;

		for(int i= ((N&1)?(N-1):(N-2)); i>=0; i-=2)
			max_arr[i] = d--;

		
		min_sum = 0;
		max_sum = 0;
		for(int i=0; i<N-1;i++){
			min_sum+=max(min_arr[i], min_arr[i+1]);
			max_sum+=max(max_arr[i], max_arr[i+1]);
		}

		//printf("%lld %lld\n", max_sum,min_sum);

		if(K<min_sum || K>max_sum){
			printf("-1\n");
			continue;
		}

		ll c = min_sum;

		int l=1, r=N, x=0;


		while(c<max_sum && c+((ll)(r-l-1))<=K){
			c+=((ll)(r-l-1));
			perm_arr[x++] = l++;
			perm_arr[x++] = r--;

		}

		for(int i=l; i<=r; i++)
			perm_arr[x++] = i;


		if(c<K){
			int s = ((int)(K-c));

			for(int i=0; i<s; i++)
				perm_arr[N-i-1] = perm_arr[N-i-2];
			perm_arr[N-s-1] = r;
		}

		ans=0;
		for(int i=0; i<N-1;i++)
			ans+=max(perm_arr[i], perm_arr[i+1]);

		assert(ans == K);
	//	if(ans==K){
			for(int i=0; i<N;i++)
				printf("%d ",perm_arr[i]);
			printf("\n");
	//	}


	}
	return 0;
}

