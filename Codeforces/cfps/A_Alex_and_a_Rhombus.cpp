#include <bits/stdc++.h>

using namespace std;

void solve(int case_num = 0) {
	int n;
	cin >> n;
	int res = 1;
	for (int i = 2; i <= n; i++) {
		res += 4 * (i - 1);
	}
	cout << res;
}

int main() {
	const string usaco_file = "";
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	if (usaco_file.length()) {
		freopen((usaco_file + ".in").c_str(), "r", stdin);
		freopen((usaco_file + ".out").c_str(), "w", stdout);
	}
	solve();
	return 0;
}