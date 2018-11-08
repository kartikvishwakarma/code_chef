#include <cstdio>
#include <queue>
#include <utility>
#include <set>
#include <iterator>
using namespace std;

int m, n;
int grid[2007][2007];

bool vis[2007][2007];

int bfs(int a, int b) {
	queue<pair<int, int> > q;
	q.push(make_pair(a, b));
	
	int k = 0;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		if (vis[cur.first][cur.second]) {
			continue;
		}
		vis[cur.first][cur.second] = true;
		k++;

		for (int di = -1; di <= 1; di++) {
			for (int dj = -1; dj <= 1; dj++) {
				int ci = cur.first + di;
				int cj = cur.second + dj;
				if (ci >= 0 && ci < m && cj >= 0 && cj < n && grid[ci][cj] && !vis[ci][cj]) {
					q.push(make_pair(ci, cj));
				}
			}
		}
	}

	return k;
}

int main() {
	scanf("%d %d", &m, &n);
	set<int> items;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &grid[i][j]);
			items.insert(grid[i][j]);
		}
	}
	set<int>::iterator it;

	int ans = 0;
	for(it = items.begin(); it != items.end(); it++){
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == *it && !vis[i][j]) {
				ans = max(ans, bfs(i, j));
			}
		}
	}
}
	printf("%d\n", ans);
}
