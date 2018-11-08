#include <iostream>
#include <bitset>

using namespace std;

int main(){
	int t,n,m;
	cin>>t;

	while(t--){
		cin>>n>>m;
		bool a[n][m];
		bool row[n],col[n];
		row[n]={false};
		col[n]={false};

		bool ans=false;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
				row[i]=true;
				col[j]=true;
				if(a[i][j])
					ans=true;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<"\n";
		}	

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(ans==false)
					cout<<"-1 ";
	
				else{
					if(a[i][j])
						cout<<"0 ";
					else if(row[i]||col[j])
						cout<<"1 ";
					else
						cout<<"2 ";
				}
			}
			cout<<"\n";
		}
	}
}