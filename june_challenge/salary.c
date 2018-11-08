#include <stdio.h>
#include <limits.h>
int main(int argc, char const *argv[])
{
	int T, N,K;
	
	scanf("%d", &T);

	while(T--){
		scanf("%d %d", &N, &K);
		int a[N];
		int tmp;

		for(int i=0; i<N;i++){
			scanf("%d", &tmp);
			a[i] = tmp+K;
		}

		int count=0;

		for(int i=0; i<N;i++){
			if(a[i]%7 == 0)
				count++;
		}

		printf("%d\n", count);
	}
	return 0;
}