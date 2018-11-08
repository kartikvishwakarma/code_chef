#include <stdio.h>
#include <stdbool.h>
int main(int argc, char const *argv[])
{
	int T, X, Y, K, N, P, C;
 
	scanf("%d", &T);
 
	while(T--){
		scanf("%d %d %d %d", &X, &Y, &K, &N);
		int rest = X-Y;		
		bool flag = false;
		for(int i=0; i<N; i++){
			scanf("%d %d", &P, &C);
			if ((P>=rest && K>=C) ){
				flag = true;
			}
		}
		if (!flag)
			printf("UnluckyChef\n");
        else
            printf("LuckyChef\n");
	}
	return 0;
} 