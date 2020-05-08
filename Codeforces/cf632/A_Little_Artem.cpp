#include <bits/stdc++.h>

using namespace std;

void solve(int caseNum = 0) {
	int n, m;
	cin >> n >> m;
	char bo[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bo[i][j] = 'W';
		}
	}
	for (int i = 0; i < n; i++) bo[i][0] = 'B';
	for (int i = 0; i < m; i++) bo[0][i] = 'B';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << bo[i][j];
		}
		cout << "\n";
	}
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