#include <iostream>

using namespace std;

int main(){
	int n,t,p;
	char m, a, b, c, d ,e;

	cin >> t;

	while(t--){
		int ans = 0;
		cin >> n >> p >> m;
		for(int i=0; i<n; i++){
			cin >> a >> b >> c >> d >> e;
			//cout << a << b << c << d << e <<'\n';
			if(i>=p && (c==m || e==m) )
				ans++;
		}
		cout << ans << '\n';
	}  
}