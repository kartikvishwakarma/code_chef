#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <cassert>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define forup(i,a,b) for(int i=a; i<b; ++i)
#define fordn(i,a,b) for(int i=a; i>b; --i)
#define rep(i,a) for(int i=0; i<a; ++i)

#define dforup(i,a,b) for(i=a; i<b; ++i)
#define dfordn(i,a,b) for(i=a; i>b; --i)
#define drep(i,a) for(i=0; i<a; ++i)

#define slenn(s,n) for(n=0; s[n]!=13 and s[n]!=0; ++n);s[n]=0

#define gi(x) scanf("%d",&x)
#define gl(x) cin>>x
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf("%s",x)

#define pis(x) printf("%d ",x)
#define pin(x) printf("%d\n",x)
#define pls(x) cout<<x<<" "
#define pln(x) cout<<x<<"\n"
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12f\n",x)
#define pnl() printf("\n")

#define fs first
#define sc second

#define pb push_back

const int inv=1000000000;
const int minv=-inv;

const int max_n=100000+5;

LL eval(int n, int p[])
{
  LL ret=0ll;
  rep(i,n-1)
    ret+=((LL)(max(p[i],p[i+1])));
  return ret;
}

int n,q; LL k;
int minp[max_n],maxp[max_n];
int rp[max_n];
LL minf,maxf;

int main()
{
  gi(q);
  rep(z,q)
  {
    gi(n); gl(k);

    rep(i,n)
      minp[i]=i+1;
    minf=eval(n,minp);

    int d=n;
    for(int i=1; i<n; i+=2)
      maxp[i]=(d--);
    for(int i=((n&1)?n-1:n-2); i>=0; i-=2)
      maxp[i]=(d--);
    maxf=eval(n,maxp);

    


    if(k<minf or k>maxf)
    {
      pin(-1);
      continue;
    }

    LL c=minf;
    int l=1,r=n,x=0;
    while(c<maxf and c+((LL)(r-l-1)) <= k)
    {
      c+=((LL)(r-l-1));
      rp[x++]=l++;
      rp[x++]=r--;
    }

    for(int i=l; i<=r; ++i)
      rp[x++]=i;

    if(c<k)
    {
      int s=((int)(k-c));
      rep(i,s)
        rp[n-1-i]=rp[n-1-i-1];
      rp[n-1-s]=r;
    }


    //assert(eval(n,rp)==k);
    rep(i,n)
      pis(rp[i]);
    pnl();
  }
  
  return 0;
}