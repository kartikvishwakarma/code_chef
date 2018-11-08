#include <iostream>

using namespace std;

void solve(int ans[], int n){

	for(int i=1; i<=n; i++){
		if(ans[i]>=4){
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
}


int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);

    int t,n;

    cin >> t;

    while(t--){
    	cin >> n;

    	int a[n+1], ans[n+1];
    	ans[n+1] = {0};

    	for(int i=1; i<=n; i++)
    		cin >>a[i];

    	for(int i=1; i<=n; i++)
    		a[i] = a[a[i]];
    	
    	for(int i=1; i<=n; i++)
    		cout << a[i] << ' ';
    	cout << '\n';

    	for(int i=1; i<=n; i++)
    		ans[a[i]]++;

    	for(int i=1; i<=n; i++)
    		cout << ans[i] << ' ';
    	cout << '\n';

    	solve(ans, n);

    }
}