#include <stdio.h>
#include <stdlib.h>



int digit = 60;
// Function that convert Decimal to binary

void show(int *arr){
    for(int i=digit-1; i>=0; i--)
        printf("%d", arr[i]);
    printf("\n");
}


int  *decToBinary(long long n)
{
    int no_ones = 0;
    // Size of an integer is assumed to be 32 bits
    int  *binary = (int *)malloc(sizeof(int) * digit);

    for (long long  i = digit-1; i >= 0; i--) {
        long long k = n >> i;
        if (k & 1){
     //       printf("1");
            no_ones++;
            binary[i] = 1;
        }
        else
      //      printf("0");
            binary[i] = 0;
    }
    printf("\n");

    return binary;
}
 
// driver code
int main()
{
    long long A = 32, B = 21;

    int *ones_A = decToBinary(A);
    int *ones_B = decToBinary(B);

    show(ones_A);
    show(ones_B);
    return 0;

}
    