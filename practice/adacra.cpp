#include <iostream>

using namespace std;
char a[100];

int main(){
	int T, N;

	cin>>T;
	string str;
	while(T--){
		cin>>str;
		//cout<<str.length();
		int u=0;
		int d=0;

		for(int i=0; i<str.length(); i++){
			//cout<<"bang!!\n";
			//cout<<str[i]<<" ";
			if(str[i]=='U'){
				while(str[i] == str[i+1])
					i++;
				u++;
			}

			else if(str[i] == 'D'){
				while(str[i]==str[i+1])
					i++;
				d++;
			}
		}
		int ans = (u>d)?d:u;
		cout<<ans<<endl;
	}
	return 0;
}