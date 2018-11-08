#include <cstdio>
#include <cstring>

void sieve_sundaram(int n){
	int m = (n-2)/2; // 2*n + 2;

	bool a[m+1];

	memset(a, false, sizeof(a));

	for(int i=1; i<n; i++){
		for(int j=i; (i+j+ 2*i*j)<m; j++){
			a[i+j+2*i*j] = true;
		}
	}

	if(n>2)
		printf("2 ");

	for(int i=1; i<=m;i++){
		if(a[i] == false)
			printf("%d ",2*i+1);
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	int n = 20;
	sieve_sundaram(n);
	return 0;
}