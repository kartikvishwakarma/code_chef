#include <cstdio>
#include <cstring>

void sieve_eratosthenes(int n){
	bool a[n+1];
	memset(a, true, sizeof(a));

	for(int i=2; i*i<=n; i++){
		if(a[i]){
			for(int j=2*i; j<=n; j+=i)
				a[j] = false;
		}
	}

	for(int i=2; i<=n; i++){
		if(a[i])
			printf("%d ", i);
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	sieve_eratosthenes(500);
	return 0;
}