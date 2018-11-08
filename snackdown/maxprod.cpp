#include <iostream>
#include <vector>
#include <set>
#define mod 1000000007
using namespace std;

vector<int> v;
set<int> s;

long solve(int n, int k){
	if(k==1)
		return n;
	if(k==0)
		return 0;

	int res = n/k+1;
	if(s.find(res) == s.end()){
		s.insert(res);
		return solve(n-res, k-1);
	}
	//cout << res << ' ' ;//<< (n-res) << ' '; 
	return solve(n-res-1, k-1);
}

int main(){
	int t,n,k, ans, res1, res2;
	/*long n,ans;

	for(int i=0; i<=500; i++)
		v.push_back(i);

	int size = v.size()/2;
	bool row[size+1][500+1];

	for(int i=0;i<=500; i++)
		row[0][i] = true;
	for(int i=0; i<=size; i++)
		row[i][0] = false;

	//row[0][0] = false;


	for(int i=1; i<=size; i++)
		for(int j = 1; j<=500; j++){
			if(i-v[j] >= 0)
				row[i][j] = row[i][j-1] || row[i-v[j]][j-1];
			else
				row[i][j] = row[i][j-1];
		}

	/**/
	cin >> t;

	while(t--){
		cin >> n >> k;
		//cout << n << ' ' << k << '\n';
		ans = solve(n,k);
		for(auto l : s)
			cout << l << ' ';
		cout<< ans << '\n';
		s.clear();
		//vector<int> v;
		//cout << ans << '\n';
	}

	/*for(int i=0; i<=size; i++){
		for(int j=0; j<=500; j++)
			cout << row[i][j] << ' ';
		cout << '\n';
	}*/

} 