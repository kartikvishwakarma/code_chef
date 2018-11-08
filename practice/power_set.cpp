#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void pow_set(int a[], int n, int m){
	int size = (int)pow(2,n);
	vector<int> tmp;
	int count=0;
	for(int i=1;i<size-1; i++){
		int p=0;
		for(int j=0;j<=n;j++){
			if(i &(1<<j))
				p+=a[j];
		}
		if(p%m==0){
			//printf("%d : ", p);
			count++;
		}

		tmp.push_back(p);
		//printf("\n");
	}

	sort(tmp.begin(), tmp.end());
	/*
	for(int i=0;i<tmp.size(); i++)
		printf("%d ", tmp[i]);
	printf("\n");
	*/
	printf("%d\n", count);
}


int main(){
	int t,m,n;
	scanf("%d",&t);

	while(t--){
		scanf("%d%d",&n,&m);
		int a[n];

		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		pow_set(a,n,m);
	}
}