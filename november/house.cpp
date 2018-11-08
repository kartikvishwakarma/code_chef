#include <iostream>
//#include <map>
#include <algorithm>
#include <climits>
#include <stack>
#include <cstdio>

using namespace  std;

typedef long long ll;

int max_sum(int a[], int n){
	stack<int>s;
	int i=0, index;
	int max_sum=0;
	int max_sum_curr=0;

	while(i<n){
		if(s.empty() || a[s.top()] <= a[i])
			s.push(i++);
		
		else{
			index = s.top();
			s.pop();

			max_sum_curr = a[index] * (s.empty()?  i : i-s.top()-1);

			if(max_sum_curr > max_sum)
				max_sum = max_sum_curr;
			}
		}

	while(!s.empty()){
		index = s.top();
		s.pop();
		max_sum_curr = a[index] * (s.empty()?  i : i-s.top()-1);

		if(max_sum_curr > max_sum)
			max_sum = max_sum_curr;
	}

	return max_sum;
}

int main()
{
	int t,n,m, p;
	int ans;
	scanf("%d", &n);

	while(t--){
		cin >> n >> m;
		int a[n+1]={0};

		for(int i=0; i<m; i++){
			cin >> p;
			a[p]++;
		}

		ans = max_sum(a, n+1);

		cout << ans << '\n';
	}
}