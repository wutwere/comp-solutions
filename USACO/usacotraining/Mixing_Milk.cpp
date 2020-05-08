/*
ID: blitesa1
LANG: C++14
PROG: milk
*/
#include <bits/stdc++.h>

using namespace std;

void solve(int caseNum = 0) {
	int n, m, c = 0;
	cin >> n >> m;
	vector<array<int, 2>> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i][0] >> a[i][1];
	}
	sort(a.begin(), a.end());
	for (int i = 0; n > 0; i++) {
		int buy = min(n, a[i][1]);
		n -= buy;
		c += buy * a[i][0];
	}
	cout << c << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef TESTING
	const string fileName = "milk";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
	#endif
	solve();
	return 0;
}