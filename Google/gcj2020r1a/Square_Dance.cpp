#include <bits/stdc++.h>

using namespace std;

void solve(int caseNum = 0) {
	int r, c;
	cin >> r >> c;
	long long grid[r][c];
	bool eliminated[r][c];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> grid[i][j];
			eliminated[i][j] = 0;
		}
	}
	long long total = 0, killed = 0;
	do {
		killed = 0;
		// add interest to total
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (!eliminated[i][j]) {
					total += grid[i][j];
				}
			}
		}
		// remove dancers
		for (int i = 0; i < r; i++) {
			//cout << "\n";
			for (int j = 0; j < c; j++) {
				//cout << grid[i][j] << " ";
				if (!eliminated[i][j]) {
					long long sum = 0;
					long long nbs = 0;
					// find neighbors left, right, up, down
					for (int k = i - 1; k >= 0; k--) {
						if (grid[k][j] != 0) {
							sum += grid[k][j];
							nbs++;
							break;
						}
					}
					for (int k = i + 1; k < r; k++) {
						if (grid[k][j] != 0) {
							sum += grid[k][j];
							nbs++;
							break;
						}
					}
					for (int k = j - 1; k >= 0; k--) {
						if (grid[i][k] != 0) {
							sum += grid[i][k];
							nbs++;
							break;
						}
					}
					for (int k = j + 1; k < c; k++) {
						if (grid[i][k] != 0) {
							sum += grid[i][k];
							nbs++;
							break;
						}
					}
					if (nbs > 0 && grid[i][j] * nbs < sum) {
						eliminated[i][j] = 1;
						killed++;
					}
				}
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (eliminated[i][j]) {
					grid[i][j] = 0;
				}
			}
		}
	} while (killed > 0);
	cout << total << "\n";
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
		cout << "Case #" << caseNum << ": ";
		solve(caseNum);
	}
	return 0;
}