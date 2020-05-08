#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;
long long n, k, sum = 0;
map<int, bool> edge[MAXN];
vector<array<int, 3>> dists;
bool good[MAXN];

int dfs(int city, int dist) {
	int children = 0;
	for (auto p : edge[city]) {
		edge[p.first].erase(city);
		children++;
		children += dfs(p.first, dist + 1);
	}
	// cerr << city << " " << children << "\n";
	dists.push_back({children - dist, -dist, city});
	return children;
}

void dfs2(int city, int dist) {
	for (auto p : edge[city]) {
		dfs2(p.first, dist + good[city]);
	}
	// cerr << city << " " << dist << "\n";
	if (!good[city]) sum += dist;
}

void solve(int caseNum = 0) {
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		edge[u][v] = 1;
		edge[v][u] = 1;
	}
	dfs(1, 0);
	sort(dists.begin(), dists.end());
	reverse(dists.begin(), dists.end());
	fill(good, good + MAXN, 0);
	for (int i = 0; i < n - k; i++) {
		// cerr << dists[i][2] << " " << dists[i][0] << "\n";
		good[dists[i][2]] = 1;
	}
	dfs2(1, 0);
	cout << sum << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#else
	const string fileName = "";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
#endif
	if (0) {
		int T;
		cin >> T;
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			//cout << "Case #" << caseNum << ": ";
			solve(caseNum);
		}
	} else solve();
	return 0;
}