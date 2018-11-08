#include <iostream>
#include <iterator>
#include <unordered_set>

using namespace std;

void rec_pow_set(int a[], int n, int sum, int curr, unordered_set<int>  &S){
	if(curr>n)
		return;

	if(curr==n){
		cout<<sum<<" ";
		S.insert(sum);
	}

	//rec_pow_set(a,n,sum+a[curr], curr+1, S);
	//cout<<*S.begin()<<" ";
	rec_pow_set(a,n,sum, curr+1, S);
	rec_pow_set(a,n,sum+a[curr], curr+1, S);
}


void pow_set(int a[], int n){
	unordered_set<int> S;

	rec_pow_set(a,n,0,0,S);

	unordered_set<int>::iterator it;
	/*
	for(it=S.begin(); it!= S.end(); it++)
		cout<<*it<<"\n";
	*/
}

int main(){
	int a[] = {1,2,3};
	int n = sizeof(a)/sizeof(a[0]);

	pow_set(a,n);
}