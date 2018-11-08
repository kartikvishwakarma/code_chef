#include <iostream>
#include <cstring>
#include <map>
using namespace std;

bool fun(bool a[]){
	for(int i=0;i<3;i++)
		if(a[i]==false)
			return false;
	return true;
}

int main(){
	int t;
	char top[3],bot[3];
	cin>>t;

	while(t--){
		bool a[3];
		memset(a,false, sizeof(a));
		map<char, int> m;
		for(int i=0;i<3;i++)
			cin>>top[i];
		for(int i=0;i<3;i++)
			cin>>bot[i];
		int no_b=0, no_c=0;
		
		bool f = true;
		int i;
		

		for( i=0;i<3;i++){
			if(top[i]=='b' || bot[i]=='b')
				no_b++;

			else if(top[i]=='o' || bot[i]=='o')
				no_c++;
			
			else{
				f = false;
				break;
			}

		}
		if(f && no_c==1 && no_b==2)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
}