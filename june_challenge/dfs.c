#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
	int n,m, tmp;;
	scanf("%d %d", &n, &m);
	int a[n][m];
	int visited[n][m];

	for(int i=0; i<n;i++){
		for(int j=0; j<m; j++){
			scanf("%d", &a[i][j]);
			visited[i][j] = 0;
		}
	}

	for(int i=0; i<n;i++){
		for(int j=0; j<m; j++){
			if (a[i][j] && !visited[i][j]){
				visited[i][j] = 1;
			}
		}
		printf("\n");
	}	
	return 0;
}