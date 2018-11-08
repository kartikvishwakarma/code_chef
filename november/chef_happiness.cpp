#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
	int t,n;

	cin >> t;

	while(t--){
		cin >> n;

		int a[n];
		map<int, vector<int> > m;

		for(int i=0; i<n; i++)
			cin >> a[i];

		for(int i=0; i<n; i++){
			m[a[i]].push_back(i+1);
		}


		/*for(auto &p : m){
			cout << p.first << " | ";
			for(auto l : p.second)
				cout<< " --> " << l ;
			cout << '\n';
		}*/


		for(auto &p : m){
			vector<int> tmp;
		
			for(auto l : p.second){
				if(m.find(l) != m.end()){
					tmp.insert(tmp.end(), m[l].begin(), m[l].end());
				}
			}
			m[p.first] = tmp;
		}
		/*cout << "\n-------------------------\n";

		for(auto &p : m){
			cout << p.first << " | ";
			for(auto l : p.second)
				cout<< " --> " << l ;
			cout << '\n';
		}*/


		bool flag=false;
		
		for(auto &p : m){
			if(m[p.first].size() == 0){
				flag = true;
				break;
			}
		}

		if(flag)
			cout << "Truly Happy\n";
		else
			cout << "Poor Chef\n";

	}
}