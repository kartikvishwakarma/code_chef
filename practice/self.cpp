#include <iostream>

using namespace std;

void next_palindrom(string str, int N){
	
}

int main(int argc, char const *argv[])
{
	/* code */
	int T, K,N;
	string str;
	cin>>T;

	while(T--){
		cin>>str;
		N = str.length();
		//cout<<N<<"\n";

		next_palindrom(str, N);
	}
	return 0;
}