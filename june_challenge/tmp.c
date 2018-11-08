#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int T,count;
	long long A,B, tmp;
	bool flag;
	scanf("%d", &T);

	while(T--){
		scanf("%lld %lld", &A, &B);
		tmp = B - floor((B-1)/(double)A)*A;
		if(tmp>0)
			printf("%lld\n", tmp);
		else
			printf("-1\n");
	}

	return 0;
}