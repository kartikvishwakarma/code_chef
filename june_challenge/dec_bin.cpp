#include <iostream>
#include <string>

using namespace std;

int digit = 60;
// Function that convert Decimal to binary



void /*long long*/ decToBinary(long long n)
{
    int no_ones = 0;
    // Size of an integer is assumed to be 32 bits
    string str = "";

    for (long long  i = digit-1; i >= 0; i--) {
        long long k = n >> i;
        if (k & 1){
     //       printf("1");
            no_ones++;
            str += '1';
        }
        else
      //      printf("0");
            str += '0';
    }
    long long num = stoll(str,0,10);
    cout<<num<<"\n";

    //return atoll(str);
}
 
// driver code
int main()
{
    long long A = 32, B = 21;

    //long long ones_A = decToBinary(A);
    //long long ones_B = decToBinary(B);
    decToBinary(A);
    decToBinary(B);
    //show(ones_A);
    //show(ones_B);
    return 0;

}
    