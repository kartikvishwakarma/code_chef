#include <iostream>
#include <algorithm>
using namespace std;

const int size = (int)1e5+1;


void show(int a[], int n){
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}

int main(){
	int n,m,l,r,q,ans;

	cin>>n;
	int a[n]={0};
	cin>>m;

	for(int i=0;i<m;i++){
		cin>>l>>r;
		a[l-1]+=1;
		a[r]+=-1;
	}

	for(int i=1;i<n;i++)
		a[i]+=a[i-1];

	cin>>q;

	sort(a,a+n);

	while(q--){
		cin>>l;
		ans = lower_bound(a,a+n,l)-a;
		cout<<n-ans<<"\n";
		
		//show(a,n);
	}

	//

}