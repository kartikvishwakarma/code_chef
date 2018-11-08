#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <utility>
#include <set>

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
 
int size = (int)1e6+7;
vector<int> val;
vector<pair<int,int> >diff_val;
set <int> uni;

void show(){
	vector<pair<int,int> >::iterator p;

	for(p=diff_val.begin(); p!=diff_val.end(); p++){
		cout<<p->first<<" "<<p->second<<"\n";
	}
}


int main(){
	int N,p,diff;
	long int sum=0;
	cin>>N;

	for(int i=0;i<N;i++){
		cin>>p;
		val.push_back(p);
		uni.insert(p);
	}
	sort(val.begin(), val.end());
	set<int>::iterator it;

	for(it = uni.begin(); it!=uni.end(); it++){
		diff= (upper_bound(val.begin(), val.end(), *it)-val.begin())-
		(lower_bound(val.begin(), val.end(), *it)-val.begin());
		//cout<<diff<<" ";
		diff_val.push_back(make_pair(diff, *it));																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																													
	}
	sort(diff_val.begin(), diff_val.end(), )
	show();
}