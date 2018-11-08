#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
	int T,count;
	long long A,B, tmp;
	bool flag;
	scanf("%d", &T);

	while(T--){
		count = 0;
		flag = true;
		scanf("%lld %lld", &A, &B);
		tmp = A;

		while(flag){
			tmp = ((tmp^B)+1);
			count++;

			if (tmp == B){
				printf("%d\n",count);
				flag = false;
			}

			else if(tmp == A){
				printf("-1\n");
				flag = false;
			}
			//tmp -= B;

			//printf("%lld\n", tmp);
		}
	}

	return 0;
}