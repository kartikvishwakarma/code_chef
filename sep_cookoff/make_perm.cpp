#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(){
	int t,n,p;

	cin>>t;

	while(t--){
		cin>>n;
		/*long ans=0;
		map<int, int> m;
		for(int i=0; i<n; i++){
			cin>>p;
			if(1<=p && p<=n){
				if(m.find(p) != m.end())
					ans++;
				else
					m[p]=1;	
			}
			else 
				ans++;
		}*/
		
		

		int a[n];

		for(int i=0; i<n; i++){
			cin>>a[i];
		}

		sort(a, a+n);

		long ans = 0;

		for(int i=0; i<n; i++){
			if(a[i] != i+1)
				ans++;

		}
		cout<<ans<<"\n";
	}
}