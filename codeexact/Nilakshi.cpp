#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int t;
	string st1, st2;
	cin>>t;
	while(t--){
		cin>>st1>>st2;
		//cout<<st1<<" "<<st2<<"\n";
		int n=0,m=0;

		for(int i=0;i<st1.length();i++)
			if(st1[i]=='1')
				n++;

		for(int i=0;i<st2.length();i++)
			if(st2[i]=='1')
				m++;

		cout<<n<<" "<<m<<"\n" ;
		int val[m+n-1];
		int  p = m+n-2, t=0;
		int k=1; 
		int c=0;

		if(min(m,n)==1){
			for(int i=0;i<max(m,n);i++)
				cout<<1;
			cout<<"\n";
		}
		else {
			for(int i=0;i<min(m,n);i++){
				val[p]=k;
				val[t]=k;
				c = (k+1)/10; p--; 
				t++; k = (k+1+c)%10;

			}

			for(int i=0; i<(m-n); i++)
				val[p]=k;

			for(int i=0;i<m+n-1;i++)
				cout<<val[i];
			cout<<"\n";
		}
	}
}