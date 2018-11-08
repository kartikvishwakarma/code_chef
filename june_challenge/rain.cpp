#include <iostream>

using namespace std;
//int A[107];

struct Point{
	int left;
	int right;
};



int main(int argc, char const *argv[])
{
	int T,N,l;
	cin>>T;
	int rainbow[] = {1,2,3,4,5,6,7,6,5,4,3,2,1};
	
	while(T--){
		cin>>N;
		int A[7] = {0};
		bool flag = true;
		for(int i=0; i<N;i++){
				cin>>l;
				A[l-1]++;
		}
		
		
		int sum = 0;
		for(int i=0;i<6;i++)
			sum+=A[i];

		if(sum+A[6] != N)
			cout<<"no\n";
		else cout<<"yes\n";

	}
	return 0;
}