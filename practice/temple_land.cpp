#include <iostream>

using namespace std;

int main()
    {
        int t, n, i, j;
 
        cin >> t;
 
        while(t--)
            {
                bool ans = 1;
 
                cin >> n;
				int a[n+1]; 
                for(i = 1; i <= n; i++)
                    cin >> a[i];
 
                if(a[1] != 1 || a[n] != 1)
                    ans = 0;
 
                for(i = 1; i <= n/2+1; i++)
                    if(a[i] != i)
                        ans=0;
                   
                j=1;
                for(i = n; i >= n/2+1; i--)
                    if(a[i] != j)
                        ans=0;
                    else
                        j++;
 
                if(ans)
                    cout << "yes" << endl;
                else
                    cout << "no" << endl;
            }
 
        return 0;
    }