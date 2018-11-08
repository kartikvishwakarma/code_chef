#include <stdio.h>

void shuffle_operation(long long A, long long B){
	long long tmp_A, tmp_B;
	tmp_A = A;
	tmp_B = B;

	int count = 0;
	/*
	while(A != B){
	
		while((tmp_A<<1) < tmp_B){
			A = A<<1;
			
			}
		tmp_A = A;
		tmp_B = A;
		A += 1;
		count++;
		tmp_A = tmp_A^A;

		}
	*/

	long long A1, A2, A3,A4, A_shift;
	
	if (A<B){
		if (B){//%A==0){
		//if (A%2==0 || A == 1){
			A_shift = B;
			A2 = A;
			while (A != B){
				while((A2<<1) < A_shift)
					A2 = A2<<1;
					//printf("%lld  ", A2);
					count++;
					if (A_shift == B){
						A3 = A2;
						A = A2 + 1;
					}
					else {
						A3 = A2 + A4;//_shift;  
						A = A2 + A4 + 1;

					}
					
					printf("%lld\n", A);
					A4 = A3;
					A_shift = A2;
					A2 = 1;//A3^A;
					//count++;
				
			}
		}

		//else if (A>2 && A%2==1){
		else{
			count++;
			A = 1;
			A_shift = B;
			A2 = A;
			while (A != B){
				while((A2<<1) < A_shift)
					A2 = A2<<1;
					//printf("%lld  ", A2);
					if (A_shift == B){
						A3 = A2;
						A = A2 + 1;
					}
					else {
						A3 = A2 + A4;//_shift;  
						A = A2 + A4 + 1;

					}
					//printf("%lld\n", A);
					A4 = A3;
					A_shift = A2;
					A2 = 1;//A3^A;
					count++;
				
			}
		}
	}
	else {
		while (A != B){
			while((A2<<1) < A_shift)
				A2 = A2<<1;
				//printf("%lld  ", A2);
				if (A_shift == B){
					A3 = A2;
					A = A2 + 1;
				}
				else {
					A3 = A2 + A4;//_shift;  
					A = A2 + A4 + 1;

				}
				//printf("%lld\n", A);
				A4 = A3;
				A_shift = A2;
				A2 = 1;//A3^A;
				count++;
			
		}	
	}

	printf("%lld   %d\n", A, count);
}

int main(){
	int T;
	long long A,B;

	scanf("%d", &T);

	while(T--){
		scanf("%lld %lld", &A, &B);
		shuffle_operation(A,B);
	}
}