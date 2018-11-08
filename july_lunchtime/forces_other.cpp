#include <iostream>

using namespace std;

int main(){
	int t,n,m,f;

	cin>>t;

	while(t--){
		cin>>n>>m;

		string str;

		for(int i=0;i<n;i++)
			cin>>str[i];

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(str[i][j]=='1')
					h_ones[i]++;
					v_ones[i]++;
			}
		}
	}
}