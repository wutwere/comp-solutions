/*
ID: blitesa1
LANG: C++14
PROG: concom
*/

#include <bits/stdc++.h>
using namespace std;

bool controls[101][101];
int owns[101][101];

void updateDown(int i, int j) {
	for (int b = 1; b <= 100; b++) {
		if (controls[j][b] && !controls[i][b]) {
			controls[i][b] = 1;
			updateDown(i, b);
		}
	}
}

void updateControl(int i, int j, int p) {
	for (int b = 1; b <= 100; b++) {
		if (controls[b][i] && !controls[b][j]) {
			int sum = 0;
			if (p <= 50) for (int c = 1; c <= 100; c++) {
				if (b == c || controls[b][c]) {
					sum += owns[c][j];
				}
			}
			if (p > 50 || sum > 50) {
				controls[b][j] = 1;
				updateDown(b, j);
				updateControl(b, j, owns[b][j]);
			}
		}
	}
}

void solve() {
	int n;
	cin >> n;
	memset(owns, 0, sizeof(owns));
	memset(controls, 0, sizeof(controls));
	for (int a = 0; a < n; a++) {
		int i, j, p;
		cin >> i >> j >> p;
		owns[i][j] = p;
		if (p > 50) {
			controls[i][j] = 1;
			updateDown(i, j);
		}
		updateControl(i, j, p);
	}
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (i != j && controls[i][j]) {
				cout << i << " " << j << "\n";
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// freopen("concom.in", "r", stdin);
	// freopen("concom.out", "w", stdout);
	solve();
	return 0;
}

