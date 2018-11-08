// A O(n) time and O(1) extra
// space solution to calculate
// the Permutation Coefficient
#include <iostream>
using namespace std;
 
int PermutationCoeff(int n, int k)
{
    int Fn = 1, Fk, Fc;
    
    // Compute n! and (n-k)!
    for (int i = 1; i <= n; i++)
    {
        Fn *= i;
        if (i == n - k)
            Fk = Fn;
        if (i==k)
            Fc=Fn;
    }
    int coeff = Fn / (Fk*Fc);
    return coeff;
}
 
// Driver Code
int main()
{
    int n = 10, k = 2;
    cout << "Value of P(" << n << ", " << k
         << ") is " << PermutationCoeff(n, k);
 
    return 0;
}