#include <iostream>
#include <utility>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>

using namespace std;

typedef long long int ll;
const int size = 2007;
int a[size][size];
int visited[size][size];
int comp_size[size*size];

int ptr;
int parent[size*size];
int pair_comp_size[size*size];

static int dirX[] = {-1,0,0,1};
static int dirY[]  ={0,-1,1,0};


int get_parent(int p){
	return (p == parent[p]) ? p : parent[p]=get_parent(parent[p]);
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}

	map< pair<int,int>, vector<pair<int,int> > > components;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m;j++){
			if(visited[i][j])
				continue;

			queue<pair<int,int> > q;
			visited[i][j] = ++ptr;
			q.push(make_pair(i,j));
			int qt=1;
			while(!q.empty()){

				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for(int i=0;i<4;i++){
					int dx = x+dirX[i];
					int dy = y+dirY[i];

					if(!visited[dx][dy] && a[x][y] == a[dx][dy]){
						visited[dx][dy] = ptr;
						q.push(make_pair(dx,dy));
						qt++;
					}
				}
			}
			comp_size[ptr] = qt;
		}
	}

	//makeing pair

	int ans=0;

	for(int i=1; i<=ptr; i++){
		parent[i]=i;
		pair_comp_size[i]=comp_size[i];
		ans = max(pair_comp_size[i],ans);
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=0;k<4;k++){
				int dx = i+dirX[k];
				int dy = j+dirY[k];

				if(a[dx][dy] <= a[i][j])
					continue;

				components[make_pair(a[i][j], a[dx][dy])].push_back(make_pair(visited[i][j], visited[dx][dy]));

			}
		}
	}

	map< pair<int,int>, vector<pair<int,int> > >::iterator itm;
	vector<pair<int,int> >::iterator itv;
	vector<int>::iterator itvi;

	for(itm = components.begin(); itm != components.end(); itm++){
		vector<int> merged;
		for(itv = (itm->second).begin(); itv != (itm->second).end(); itv++){
			int x = itv->first;
			int y = itv->second;
			merged.push_back(x);
			merged.push_back(y);
			int xx = get_parent(x);
			int yy = get_parent(y);

			if(xx == yy)
				continue;

			if(rand() & 1)
				swap(xx,yy);

			parent[xx]=yy;
			pair_comp_size[yy]+=pair_comp_size[xx];
			ans = max(pair_comp_size[yy], ans);
		}

		for(itvi = merged.begin(); itvi != merged.end(); itvi++){
			pair_comp_size[*itvi] = comp_size[*itvi];
			parent[*itvi] = *itvi;
		}
	}

	printf("%d\n", ans);


}