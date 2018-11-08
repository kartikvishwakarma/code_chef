#include <iostream>
#include <queue>

using namespace std;

int main(){
	int N,Q,K;
	int p=0;
	char c;
	cin >> N >> Q >> K;

	string str = "";

	int len[2*N] = {0};
	
	for(int i=0; i<N; i++){
		cin >> c;
		str += c;
	}

	str += str;



	for(int i=0; i<=N; i++)
		cout << str.substr(N-i, N) << '\n';

	cout << '\n';
}