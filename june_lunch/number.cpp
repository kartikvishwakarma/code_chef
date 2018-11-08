#include <iostream>
using namespace std;

int main(){
	int T,L,R,ans;
	cin>>T;
	while(T--){
		cin>>L>>R;
		int p=0;
		for(int i=L; i<=R;i++){
			ans = i%10;

			if(ans == 2 || ans == 3 || ans ==9)
				p++;
		}

		cout<<p<<"\n";
	}

}