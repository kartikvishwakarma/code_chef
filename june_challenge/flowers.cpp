#include <iostream>
#include<cmath>
#include <vector>

using namespace std;

int n,m;
int a[100][100];
/*
int dfs( int i, int j){
	if(i<0 || j<0 || i>=n || j>=m)
		return 0;
	if(a[i][j] == 0)
		return 0;

	if(a[i][j] == 1 || a[i][j] == 2)
		a[i][j] = 1;
	else 
		a[i][j]=0;
		//return 1 + dfs( i-1,j) + dfs(i+1,j) + dfs(i,j-1) + dfs(i,j+1);
	
}
*/
int main(int argc, char const *argv[])
{
	int i,j;
	cin>>n>>m;
	 //a[n][m];

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>a[i][j];
			if(a[i][j])
		}
	}
	vector<int> res;
	

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(a[i][j] == 1){
				res.push_back(dfs( i,j));
			}
		}
	}
	int max=0;
	for(int i=0; i<res.size(); i++){
		if(max<res[i])
			max = res[i];
	}

	cout<<max<<"\n";
	return 0;
}