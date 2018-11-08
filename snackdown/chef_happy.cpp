#include <iostream>

using namespace std;


int main(){
	int t,n;

	cin >> t;

	while(t--){
		cin >> n;

		int a[n];
		int sum=0;
		int total_sum=0;

		for(int i=0; i<n; i++){
			cin >> a[i];
			sum += a[i];
			total_sum += i+1;
		}

		int res = total_sum - sum
	}
} 

