#include <iostream>

using namespace std;

const int size = (int)(1e5+1);
int m[size], n[size];

int main(){
	int t, len_n, len_m;
	string M, N;
	cin>>t;

	while(t--){
		cin>>M>>N;
		len_m = M.length();
		len_n = N.length();

		int sum_n=0;
		int sum_m=0;

		for(int i=0;i<len_m; i++){
			sum_m+=(M.at(i)-'0')%3;
		}

		for(int i=0;i<len_n; i++){
			sum_n+=(N.at(i)-'0')%3;
		}

		cout<<((sum_m*sum_n)%3)<<"\n";

	} 
}