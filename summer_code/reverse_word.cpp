#include <iostream>
#include <sstream>

using namespace std;

int main(){
	int t;
	string str;

	cin>>t;

	while(t--){
		cin>>str;

		stringstream ss(str);

		string token;

		while(getline(ss, token, '.')){
			cout<<token<<"\n";
		}
	}
}