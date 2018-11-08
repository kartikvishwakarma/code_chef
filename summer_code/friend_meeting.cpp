#include <iostream>
#include <algorithm>

using namespace std;

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;
 
    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;
 
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
 
    return true;
}

int main(){
	int n,t;

	cin>>t;

	while(t--){
		cin>>n;
		int a[n];

		for(int i=0;i<n;i++)
			cin>>a[i];

		sort(a,a+n);

		int first_prime, second_prime;
		
		if (find(a,a+n, 1) !=a+n){
			for(int i=0;i<n;i++){
				if(isPrime(a[i])){
					cout<<a[i]<<"\n";
					break;
				}
			}
		}
		else 
			cout<<"-1\n";
	}
}