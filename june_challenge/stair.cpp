#include <iostream>

using namespace std;
/*
int get_way(int step[], int N){
	if (N == 0)
		return 1;
	int A[N+1] = {0};
	int total;
	A[0] = 1;

	for(int i=1; i<=N; i++){
		total = 0;
		for(int j = 0; j<sizeof(step)/sizeof(step[0]); j++){
			if (i-step[j]>=0){
				total += A[i-step[j]];
			}
		}
		A[i] = total;
	}
	cout<<A[N]<<"\n";
}
*/

int rec_get_n(int step[], int N){
	if(N == 0)
		return 1;
	int total = 0;

	for(int j=0; j<sizeof(step)/sizeof(step[0]); j++){
		if (N-step[j]>=0)
			total += rec_get_n(step, N-step[j]);
	}
	
	return total;
}
int main(int argc, char const *argv[])
{
	int N;
	int step[] = {1,2};
	cin>>N;

	//get_way(step, N);
	cout<<rec_get_n(step, N)<<"\n";
	return 0;
}