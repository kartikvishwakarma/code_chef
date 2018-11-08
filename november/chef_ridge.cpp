#include <iostream>

using namespace std;

int main(){
	int t,n;

	cin >> t;

	while(t--){
		cin >> n;

		long num = 1;

		for(int i=3; i<=n; i++){
			if(i&1)
				num = (long)2*num + 1;
			else
				num = (long)2*num - 1;
		}

		cout << num << ' ' << (1<<n) << ' ';
	}
}