#include <iostream>
#include <iterator>
#include <set>
using namespace std;

void Disp(set<int> T){
	set<int>::iterator it;
	for(it = T.begin(); it != T.end(); it++)
		cout<<*it<<" ";
	cout<<"\n";
}

int main(int argc, char const *argv[])
{
	int n,m,i,j;
	cin>>n>>m;
	int a[n][m];
	bool index;
	set<int> items;

	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			cin>>a[i][j];
	}

	int count=0;
	//i=0; j=0;
	for(i=0;i<n;i++){
		
		cout<<"terminate :"<<i<<"\n";
		
		for(j=0;j<m;j++){
			items.clear();
			if((i-1)>=0 ){
				cout<<"up\n";
				items.insert(a[i-1][j]);
			}
			if((j+1<m)){
				cout<<"right\n";
				items.insert(a[i][j+1]);
			}
			if(i+1<n){
				cout<<"down\n";
				items.insert(a[i+1][j]);
			}
			if(j-1>=0){
				cout<<"left\n";
				items.insert(a[i][j-1]);
			}
			if(items.size()>2){
				i++; j =0;
				//items.clear();
				break;
			}
			cout<<"("<<i<<","<<j<<") "<<count++<<"\n";
		//items.clear();
		}
		//items.clear();
		//i++;
	}

	cout<<count<<"\n";
	return 0;
}