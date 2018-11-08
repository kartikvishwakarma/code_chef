# include <iostream> 
# include <cmath> 
  
using namespace std;
// A function to print all prime factors of a given number n 
bool  primeFactors(int n) 
{ 
    // Print the number of 2s that divide n 
    if(n<12)
        return false;

    int p=0;
    while (n%2 == 0) 
    { 
       // printf("%d ", 2); 
        n = n/2; 
        p += 1;
    } 
  
    // n must be odd at this point.  So we can skip  
    // one element (Note i = i +2) 
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        // While i divides n, print i and divide n 
        while (n%i == 0) 
        { 
            //printf("%d ", i); 
            n = n/i; 
            p += 1;
        } 
    } 
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2 
    if (n > 2) 
        p += 1; 

    //cout<<p<<'\n';

    if(p==3)
        return true;
    return false;
} 
  
/* Driver program to test above function */
int main() 
{ 
    int t,n;
    cin>>t;
    while(t--){ 
        cin>>n;
        bool res = primeFactors(n); 
        cout<<(res?"YES\n":"NO\n");
    }
    return 0; 
} 