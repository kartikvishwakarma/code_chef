#include <iostream>

using namespace std;

int main(){
	int n,t;
	//string str;

	cin>>t;
	while(t--){
		cin>>n;
		char ch[n];

		for(int i=0;i<n;i++)
			cin>>ch[i];

		for(int i=1; i<n;i+=2){
			char p = ch[i];
			ch[i] = ch[i-1];
			ch[i-1] = p;
		}
		for(int i=0;i<n;i++){
			ch[i]=(char)('z' - ch[i]+'a');
			cout<<(ch[i]);
		}
		cout<<"\n";
	}
}