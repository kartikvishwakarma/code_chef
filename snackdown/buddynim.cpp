#include <iostream>

using namespace std;

int main(){
	int n,m,t;

	cin >> t;

	while(t--){
		cin >> n >> m;
		int a[n], b[m];

		for(int i=0; i<n; i++)
			cin >>a[i];

		for(int i=0; i<m; i++)
			cin >> b[i];

		if(m==n)
			cout << "Bob\n";
		else
			cout << "Alice\n";
	}
}