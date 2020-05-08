/*
ID: blitesa1
LANG: C++11
TASK: test
*/
#include <bits/stdc++.h>

using namespace std;

void solve(int case_num = 0) {
	int a, b;
	cin >> a >> b;
	cout << a + b << "\n";
}

int main() {
	const string usaco_file = "test";
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	if (usaco_file.length()) {
		freopen((usaco_file + ".in").c_str(), "r", stdin);
		freopen((usaco_file + ".out").c_str(), "w", stdout);
	}
	solve();
	return 0;
}