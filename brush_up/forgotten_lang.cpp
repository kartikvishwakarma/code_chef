#include <iostream>
#include <set>

using namespace std;
 
string old_dict[1000];

int main(int argc, char const *argv[])
{
	int T, N, K,L;
	string str;
	cin>>T;

	while(T--){
		cin>>N>>K;

		for(int i=0; i<N; i++)
			cin>>old_dict[i];
		set<string> new_lang;
		while(K--){
			cin>>L;
			for(int i=0; i<L; i++){
				cin>>str;
				new_lang.insert(str);
			}
		}

		for(int i=0; i<N; i++){
			if(new_lang.find(old_dict[i]) != new_lang.end())
				cout<<"YES ";
			else cout<<"NO ";
		}
		cout<<endl;
		
	}
	return 0;
}