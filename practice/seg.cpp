#include <iostream>
#include <cmath>

using namespace std;

typedef long long int ll;

ll getmid(ll l, ll r){
	return l+(r-l)/2;
}

ll create_segment_tree(ll A[], ll l, ll r, ll *st, ll curr){
	if(l==r){
		st[curr] = A[l];
		return A[l];
	}

	ll mid = getmid(l,r);

	st[curr] = create_segment_tree(A, l, mid, st, curr*2+1) +
				create_segment_tree(A, mid+1, r, st, curr*2+2);

	return st[curr]; 
}

ll* segment_tree(ll A[], ll n){
	ll height = (ll)ceil(log2(n));

	ll max_height = 2*(ll)pow(2,height) -1;

	ll *st = new ll[max_height];

	create_segment_tree(A,1,n, st, 1);

	return st;
}

void show(ll st[], ll n){
	for(ll i=0; i<n; i++)
		cout<<st[i]<<" ";
	cout<<"\n";
}

ll get_rec_Sum(ll *st, ll l, ll r, ll start, ll end, ll curr){
	if(start <= l && end >= r )
		return st[curr];

	if(start > r || end < l)
		return 0;

	ll mid = getmid(l, r);

	return get_rec_Sum(st, l, mid, start, end, 2*curr+1) +
			get_rec_Sum(st, mid+1, r, start, end, 2*curr+2);
}

ll getSum(ll *st, ll n, ll start, ll end){
	if(start<0 || end> n-1 || start > end){
		cout<<"Invalid range input\n";
		return -1;
	}

	get_rec_Sum(st, 1, n, start, end,1);
}

void update_rec(ll *st, ll l, ll r, ll i, ll diff, ll curr){
	if(i>r || i<l)
		return;

	st[curr] = st[curr]+diff;

	if(l != r){
		ll mid = getmid(l,r);
		update_rec(st, l, mid, i, diff, 2*curr+1);
		update_rec(st, mid+1, r, i, diff, 2*curr+2);
	}
}

void update(ll A[], ll *st, ll n, ll i, ll val){
	if(i>n || i<1){
		cout<<"Invalid input\n";
		return ;
	}

	ll diff = val - A[i];
	A[i] = val;

	update_rec(st, 1, n, i, diff, 1);

}

ll Max_rec(ll *st, ll l, ll r, ll start, ll end, ll curr){
	if(start <=l && end >= r)
		return st[curr];

	if(start > r || end < l)
		return 0;

	ll mid = getmid(l ,r);

	ll left = Max_rec(st, l, mid, start, end, 2*curr+1);
	ll right = Max_rec(st, mid+1, r, start, end, 2*curr+2);

	return (right>left)?right:left;
}

ll Max(ll *st, ll n, ll start, ll end){
	if(start <1 || end > n || start > end){
		cout<<"Invalid input\n";
		return -1.;
	}

	return Max_rec(st, 1, n, start, end, 1);
}

int main(int argc, char const *argv[])
{
	int T,id;
	ll N,Q,L,R;
	cin>>T;
	while(T--){
		cin>>N>>Q;
		ll A[N+1];

		for(ll i=1;i<=N; i++)
			cin>>A[i];
		ll *st = segment_tree(A,N);
		ll mode, median;
		while(Q--){
			cin>>id;
			cin>>L>>R;

			if(id==1){
				mode = Max(st, N, L, R);
				cout<<mode<<"\n";
			}	
			else{
				update(A,st, N,L,R);
			}

		}
		
	}
	return 0;
}