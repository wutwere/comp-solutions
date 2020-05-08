/*
ID: blitesa1
LANG: C++14
PROG: maze1
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXW = 38 * 2 + 1, MAXH = 100 * 2 + 1;
const pair<int, int> dirs[2] = {{0, -1}, {-1, 0}};

int w, h, res = 0;
int dist[MAXW][MAXH];
vector<pair<int, int>> edges[MAXW][MAXH];
vector<pair<int, int>> exts;
string strs[MAXH];

void dijkstra(int x, int y, int curdist) {
	for (pair<int, int> nb : edges[x][y]) {
		int nx = nb.first, ny = nb.second;
		if (dist[nx][ny] > curdist + 1) {
			dist[nx][ny] = curdist + 1;
			dijkstra(nx, ny, curdist + 1);
		}
	}
}

void solve() {
	cin >> w >> h;
	for (int i = 0; i < w * 2 + 1; i++) {
		for (int j = 0; j < h * 2 + 1; j++) {
			dist[i][j] = 1e9;
		}
	}
	getline(cin, strs[0]);
	for (int i = 0; i < h * 2 + 1; i++) {
		getline(cin, strs[i]);
		if (i) for (int j = 1; j < w * 2 + 1; j++) {
			for (int k = 0; k < 2; k++) {
				int ni = i + dirs[k].second;
				int nj = j + dirs[k].first;
				if (strs[i][j] == ' ' && strs[ni][nj] == ' ') {
					edges[j][i].push_back({nj, ni});
					edges[nj][ni].push_back({j, i});
					if (ni == 0 || nj == 0) {
						exts.push_back({nj, ni});
					} else if (i == h * 2 || j == w * 2) {
						exts.push_back({j, i});
					}
				}
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		dijkstra(exts[i].first, exts[i].second, 0);
	}
	for (int i = 0; i < w * 2 + 1; i++) {
		for (int j = 0; j < h * 2 + 1; j++) {
			if (dist[i][j] < 1e9) {
				res = max(res, dist[i][j]);
			}
		}
	}
	cout << (res + 1) / 2 << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifndef LOCAL
	freopen("maze1.in", "r", stdin);
	freopen("maze1.out", "w", stdout);
#endif
	solve();
	return 0;
}

