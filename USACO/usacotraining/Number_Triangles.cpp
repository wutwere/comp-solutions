/*
ID: blitesa1
LANG: C++14
PROG: numtri
*/
#include <bits/stdc++.h>

using namespace std;

int r, sum = 0, result = 0;
int tri[1000][1000], dp[1000][1000];

/*void search(int row = 0, int col = 0) {
	cout << row << " " << col << "\n";
	int val = tri[row][col];
	sum += val;
	result = max(sum, result);
	if (row + 1 < r) for (int i = 0; i < 2; i++) {
		if (col + i < r + 1) search(row + 1, col + i);
	}
	sum -= val;
}*/

int value(int row, int col) {
	if (row >= 0 && col >= 0 && row < r && col < r + 1) return dp[row][col];
	return 0;
}

void solve(int caseNum = 0) {
	cin >> r;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> tri[i][j];
			dp[i][j] = max(value(i - 1, j - 1), value(i - 1, j)) + tri[i][j];
			result = max(result, dp[i][j]);
		}
	}
	//search();
	cout << result << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef TESTING
	const string fileName = "numtri";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
	#endif
	solve();
	return 0;
}