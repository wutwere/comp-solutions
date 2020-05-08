#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	string grid[n];
	vector<vector<long long>> paths(n, vector<long long>(n));
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}
	paths[0][0] = grid[0][0] != '*';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == '*') {
				continue;
			}
			if (i && grid[i - 1][j] != '*') {
				paths[i][j] += paths[i - 1][j];
			}
			if (j && grid[i][j - 1] != '*') {
				paths[i][j] += paths[i][j - 1];
			}
			paths[i][j] %= (int) 1e9 + 7;
		}
	}
	cout << paths[n - 1][n - 1] << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}