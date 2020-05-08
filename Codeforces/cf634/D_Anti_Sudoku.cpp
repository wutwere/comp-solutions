#include <bits/stdc++.h>

using namespace std;

void solve(int caseNum = 0) {
	int grid[9][9];
	for (int i = 0; i < 9; i++) {
		int n;
		cin >> n;
		for (int j = 8; j >= 0; j--) {
			int d = n % 10;
			grid[i][j] = d;
			n -= d;
			n /= 10;
		}
	}
	for (int i = 0, j = 0; i < 9; i++) {
		grid[j][i] %= 9;
		grid[j][i]++;
		j += 3;
		if (i == 2 || i == 5) j++;
		j %= 9;
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << grid[i][j];
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