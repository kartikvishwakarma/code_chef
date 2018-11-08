#include <stdio.h>

int main(){
	int T, N, A, B, var, no_A, no_B;
	scanf("%d", &T);

	while(T--){
		no_B=0;
		no_A=0;

		scanf("%d %d %d", &N, &A, &B);
		double tmp[N];

		for(int i=0; i<N; i++)
			tmp[i]=0;

		for(int i=0; i<N; i++){
			scanf("%d", &var);
			tmp[var-1]++;
		}
		printf("%.10f\n", (tmp[A-1]/N)*(tmp[B-1]/N));

	}
	return 0;
}