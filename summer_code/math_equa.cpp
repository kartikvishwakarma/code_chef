#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>
#include <cmath>
#include <map>
#define mod 1000000009

using namespace std;
typedef long long int li;

map<pair<li,li>, li> Pair;
map<li, pair<li, li> > val;
map<li, pair<li,li> >::iterator it;
map<li,li> times;

li gcdExtended(li a, li b, li *x, li *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    li x1, y1; // To store results of recursive call
    li gcd = gcdExtended(b%a, a, &x1, &y1);
 
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}


li modInverse(li a, li m)
{
    li x, y;
    li g = gcdExtended(a, m, &x, &y);
       // m is added to handle negative x
    li res = (x%m + m) % m;
        
    return res;
}
 

li value_at(li a, li b){
	li tmp = (4*a*b+2*max(a,b));
}


int main(){
	li n,q,k,a,b,x,y,res;

	cin>>n>>q;

	for(int i=0;i<n;i++){
		cin>>a>>b;
		//Pair[{a,b}]++;
		//cout<<value_at(a,b)<<"\n";
		res = value_at(a,b); 
		val[res]= make_pair(a,b);
		times[res]++;
		
	}

	while(q--){
		cin>>a;
		//cout<<a<<"\n";
		li ptr = a*(a+1);
		it = val.find(ptr);
		if(it == val.end())
			cout<<"-1\n";
		else{
			li ans = modInverse(times[ptr], mod);
			cout<<ans<<"\n";
		}
	}
	val.clear();
	Pair.clear();
}