#include <iostream>

using namespace std;

typedef long long int ll;

// C++ program to print distinct subset sums of
// a given array.
#include<bits/stdc++.h>
using namespace std;

// Uses Dynamic Programming to find distinct
// subset sums
void printDistSum(int arr[], int n, int m)
{
	ll sum = 0;

	unordered_map<ll, ll> map;

	for (int i=0; i<n; i++)
		sum += arr[i];

	// dp[i][j] would be true if arr[0..i-1] has
	// a subset with sum equal to j.
	bool dp[n+1][sum+1];
	memset(dp, 0, sizeof(dp));

	// There is always a subset with 0 sum
	for (int i=1; i<=n; i++)
		dp[i][0] = true;

	// Fill dp[][] in bottom up manner
	for (int i=1; i<=n; i++)
	{
		dp[i][arr[i-1]] = true;
		for (int j=1; j<=sum; j++)
		{
			// Sums that were achievable
			// without current array element
			if (dp[i-1][j] == true)
			{
				dp[i][j] = true;
				dp[i][j + arr[i-1]] = true;
				map[j+arr[i-1]]++;
				map[j]++;
			}
		}
	}

	// Print last row elements
	ll p=0;
	/*
	for (ll j=1; j<sum; j++)
		if (dp[n][j]==true){// && j%m==0){
			p++;
			cout << j << " ";
		}
	cout<<p<<"\n";
	*/
	for(auto p:map){
		cout<<p.first<<" | "<<p.second<<"\n";
	}
	cout<<"\n\n";
}


int main(){
	int T,n,m;

	cin>>T;

	while(T--){
		cin>>n>>m;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];

		printDistSum(a,n,m);
	}
}