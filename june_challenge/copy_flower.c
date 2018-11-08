#include <stdio.h>
#include<math.h>
int n,m,ct;
int a[2007][2007];

void check(int i,int j){
	if(a[i][j]==0)
		return;
	a[i][j]=5;
	ct++;
	
	if(i+1<n && a[i+1][j]==1 || a[i+1][j]==2)
		check(i+1,j);

	if(i-1>=0 && a[i-1][j]==1 || a[i-1][j]==2)
		check(i-1,j);

	if(j+1<m && a[i][j+1]==1 || a[i][j+1]==2)
		check(i,j+1);

	if(j-1>=0 && a[i][j-1]==1 || a[i][j-1]==2)
		check(i,j-1);
}


int main() {
	while(scanf("%d%d",&n,&m)!=EOF){
		int tt;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				tt=scanf("%d",&a[i][j]);
			}//printf("%d ",a[i][j]);}
		//puts("");
		}
		//continue;
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]==1 || a[i][j]==2){
					ct=0;
					check(i,j);
					if(ct>ans) ans=ct;
				}
			}
		}

		printf("%d\n",ans);
		}	
	return 0;
}
