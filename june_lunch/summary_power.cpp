#include <iostream>
#include <string>
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

int main(){
	SPEED;
	int N,T,K,k;
	string str, prev_str="", curr_str,tm;

	cin>>T;

	while(T--){
		cin>>N>>K;

		char ptr[N];

		cin>>ptr[0];
		int a[N] = {0};
		int power=0;
		for(int i=1;i<N;i++){
			cin>>ptr[i];
			a[i]+=a[i-1];
			if(ptr[i] != ptr[i-1])
				a[i]+=1;
		}

		for(int i=0; i<N-K; i++){
			//cout<<a[i]<<" ";
			power+=a[K+i]-a[i];
		}
		cout<<power<<"\n";
	}

}