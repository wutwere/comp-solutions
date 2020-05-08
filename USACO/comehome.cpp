/*
ID: blitesa1
LANG: C++14
PROG: comehome
*/

#include <bits/stdc++.h>
using namespace std;

map<char, map<char, int>> edge;
map<char, int> dists;
int ans = 1e9;
char ansB;

void dfs(char barn, int curDist) {
	dists[barn] = curDist;
	for (auto p : edge[barn]) {
		int newDist = curDist + p.second;
		if (!dists.count(p.first) || newDist < dists[p.first]) {
			if (p.first - 'A' >= 0 && p.first - 'A' < 25 && newDist < ans) {
				ans = newDist;
				ansB = p.first;
			}
			dfs(p.first, newDist);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b;
		int dist;
		cin >> a >> b >> dist;
		if (edge[a].count(b)) {
			edge[a][b] = min(edge[a][b], dist);
		} else {
			edge[a][b] = dist;
		}
		edge[b][a] = edge[a][b];
	}
	dfs('Z', 0);
	cout << ansB << " " << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifndef LOCAL
		freopen("comehome.in", "r", stdin);
		freopen("comehome.out", "w", stdout);
	#endif
	solve();
	return 0;
}