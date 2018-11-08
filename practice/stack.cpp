#include <iostream>
#include <stack>

using namespace std;

int max_num(int a[], int n){
	stack<int> s;
	int max_val=0;
	int max_curr;
	int ind;
	int i=0;

	while(i<n){
		if(s.empty() || a[s.top()] <= a[i])
			s.push(i++);

		else{
			ind = s.top();
			s.pop();

			max_curr = a[ind] * (s.empty() ? i : (i-s.top()-1));

			if(max_curr > max_val)
				max_val = max_curr;
		}
	}

	while(!s.empty()){
		ind = s.top();
		s.pop();

		max_curr = a[ind] * (s.empty() ? i : (i-s.top()-1) );
		if(max_curr > max_val)
			max_val = max_curr;
	}

	return max_val;

}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	int t,n,m,p;

	cin >> t;

	while(t--){
		cin >> n >> m;

		int a[n+1] = {0};

		for(int i=0; i<m; i++){
			cin >> p; 
			a[p]++;
		}

		int ans = max_num(a,n+1);
		cout << ans << '\n';
	}
}