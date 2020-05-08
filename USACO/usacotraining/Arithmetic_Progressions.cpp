/*
ID: blitesa1
LANG: C++14
PROG: ariprog
*/
#include <bits/stdc++.h>

using namespace std;

void solve(int caseNum = 0) {
	int n, m;
	cin >> n >> m;
	vector<int> bisquares;
	unordered_set<int> used;
	for (int i = 0; i <= m; i++) {
		for (int j = i; j <= m; j++) {
			if (!used.count(i * i + j * j)) {
				bisquares.push_back(i * i + j * j);
				used.insert(i * i + j * j);
			}
		}
	}
	sort(bisquares.begin(), bisquares.end());
	bool none = 1, setBinc = 0;
	int binc = 1;
	for (int b = 1; b <= (m * m * 2) / (n - 1); b += binc) {
		for (int a : bisquares) {
			if (a + b * (n - 1) > m * m * 2) break;
			bool good = 1;
			for (int i = n - 1; i >= 0; i--) {
				if (!used.count(a + i * b)) {
					good = 0;
					break;
				}
			}
			if (good) {
				if (!setBinc) {
					setBinc = 1;
					binc = b;
					none = 0;
				}
				cout << a << " " << b << "\n";
			}
		}
		if (!setBinc && b == 4) {
			binc = 4;
		}
	}
	if (none) cout << "NONE\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef TESTING
	const string fileName = "ariprog";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
	#endif
	solve();
	return 0;
}