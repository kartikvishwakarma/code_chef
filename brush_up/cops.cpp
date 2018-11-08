#include <iostream>

using namespace std;

int A[10];

int main(int argc, char const *argv[])
{
	int T,M,x,y,left_most, right_most,val;
	cin>>T;
	while(T--){
		left_most = 1;
		right_most = 100;
		cin>>M>>x>>y;

		for(int i=0; i<M; i++)
			cin>>A[i];

		val = x*y;
		int ans = 0;
		int tmp;

		ans+=(A[0]-val)-1 > 0 ? (A[0]-val):0;
		for(int i=1; i<M-1; i++){
			tmp = (A[i]-val)-(A[i-1]+val);
			ans+= (tmp>0)?tmp:0;	
		}
		tmp = 100 - (A[M-1]+val) -1;
		ans += (tmp>0)?tmp:0;
		//cout<<"!!bng\n";
		cout<<ans<<endl;
	}
	return 0;
}