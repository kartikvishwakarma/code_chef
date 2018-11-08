#include <cstdio>
const int size = (int)1e5+1;
int a[size];

int digit_sum(int n){
	int ans = n%9;
	if(ans)
		return ans;
	
	return 9;   
} 

int main(){
	int t,m,n,x,ans;
	for(int i=1; i<=size; i++){
		ans = i%9;
		if(ans==0)
			a[i]=9;
		else
			a[i]=ans;
	}

	scanf("%d",&t);

	while(t--){
		scanf("%d %d %d", &m, &n, &x);
		int tmp=0;
		for(int i=m; i<=n; i++){
			if(a[i]==x)
				tmp++;
		}

		printf("%d\n", tmp);	
	}
}