#include <iostream>
#include <iterator>
#include <cstring>
#include <map>
#include <vector>
#include <utility>
using namespace std;
//bool str[10][10];
int h_ones[10], v_ones[10];

void show(int n, int m){
	for(int i=0;i<n;i++)
		cout<<h_ones[i]<<" ";
	cout<<"\n";
	for(int i=0;i<m;i++)
		cout<<v_ones[i]<<" ";
	cout<<"\n\n";
}

void change_matrix(int n, int m, char dir){

	//cout<<dir<<"\n";
	if(dir=='L'){
		v_ones[m];
		memset(v_ones, 0, sizeof(v_ones));
		int h_tmp[n];
		bool f = true;
		for(int i=0;i<m;i++){

			for(int j=0;j<n;j++){
				if(f)
					h_tmp[j]=h_ones[j];
				if(h_tmp[j]){
					v_ones[i]+=1;
					h_tmp[j]--;
				}
			}
			f = false;
		}
	}
	else if(dir=='R'){
		v_ones[m] ;
		memset(v_ones, 0, sizeof(v_ones));
		int h_tmp[n];
		bool f = true;
		for(int i=m-1;i>=0;i--){
			for(int j=0;j<n;j++){
				if(f)
					h_tmp[j]=h_ones[j];

				if(h_tmp[j]){
					v_ones[i]+=1;
					h_tmp[j]--;
				}
			}
			f=false;	
		}
	}
	else if(dir=='U'){
		h_ones[n];
		memset(h_ones, 0, sizeof(h_ones));
		int v_tmp[m];
		bool f = true;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(f)
					v_tmp[j]=v_ones[j];

				if(v_tmp[j]){
					h_ones[i]+=1;
					v_tmp[j]--;
				}
			}
			f=false;
		}
	}
	else if(dir=='D'){
		h_ones[n] ;
		memset(h_ones, 0, sizeof(h_ones));
		int v_tmp[m];
		bool f=true;
		for(int i=n-1;i>=0;i--){
			for(int j=0;j<m;j++){
				if(f)
					v_tmp[j]=v_ones[j];

				if(v_tmp[j]){
					h_ones[i]+=1;
					v_tmp[j]--;
				}
			}
			f=false;
		}	
	}
	//show(n,m);


}

int main(){
	int t,n,m;
	//string str;

	cin>>t;

	while(t--){

		memset(h_ones, 0, sizeof(h_ones));
		memset(v_ones, 0, sizeof(v_ones));

		cin>>n>>m;
		string str[n];
		for(int i=0;i<n;i++){
			cin>>str[i];
			//cout<<str[i]<<"\n";
		}

		map<char,int> freq, index;

		string force;
		cin>>force;
		int len = force.length();
		//char p[4] = {0}; 
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				//cout<<str[i][j];
				if(str[i][j]=='1'){
					h_ones[i]+=1;	
					v_ones[j]+=1;
					//show(n,m);
				}
			}
		}
		/*
		for(int i=0;i<len;i++){
			char z = force.at(i);
			freq[z] = (freq[z]+1)%2;
			index[z] = i;
		}

		map<int, pair<int,char> >::iterator it;

		string v = "LRDU";
		map<int, pair<int,char> > tmp;

		for(int i=0;i<4;i++){
			char z = v.at(i);
			tmp[index[z]]=(make_pair(freq[z], z));
		}

		 
		//show(n,m);
		/*for(it =tmp.begin(); it!=tmp.end(); it++){
			//cout<<it->first<<" "<<(it->second).first<<" "<<(it->second).second<<"\n";
			if((it->second).first){
				int ind=it->first;
				char dir=(it->second).second;
				change_matrix(n,m,dir);
			}
		}
		*/

		for(int i=0;i<force.length(); i++){
			change_matrix(n,m,force.at(i));
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(h_ones[i]&&v_ones[j]){
					cout<<"1";
					h_ones[i]--; v_ones[j]--;
				}
				else
					cout<<"0";
			}
			cout<<"\n";
		}
		
		

		//cout<<"next test----\n";
	}
}