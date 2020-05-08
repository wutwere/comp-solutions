#include <bits/stdc++.h>

using namespace std;

void solve(int caseNum = 0) {
	int n;
	cin >> n;
	int stats[n][2];
	for (int i = 0; i < n; i++) {
		cin >> stats[i][0] >> stats[i][1];
	}
	for (int i = 0; i < n; i++) {
		if (i) {
			if (stats[i][0] < stats[i - 1][0] || stats[i][1] < stats[i - 1][1] || stats[i][1] - stats[i - 1][1] > stats[i][0] - stats[i - 1][0] || stats[i][1] > stats[i][0]) {
				cout << "NO\n";
				return;
			}
		} else {
			if (stats[i][1] > stats[i][0]) {
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef TESTING
	const string fileName = "";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
	#endif
	int T;
	cin >> T;
	for (int caseNum = 1; caseNum <= T; caseNum++) {
		//cout << "Case #" << caseNum << ": ";
		solve(caseNum);
	}
	return 0;
}