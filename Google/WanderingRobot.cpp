#include <bits/stdc++.h>
using namespace std;

void solve(int caseNum = 0) {
	int w, h, l, u, r, d;
	cin >> w >> h >> l >> u >> r >> d;
	double poss[w][h];
	auto within = [&](int x, int y) {
		return x >= 0 && x < w && y >= 0 && y < h;
	};
	auto withinHole = [&](int x, int y) {
		return x >= l - 1 && x < r && y >= u - 1 && y < d;
	};
	memset(poss, 0, sizeof(poss));
	poss[0][0] = 1;
	for (int j = 0; j < h; j++) {
		for (int i = 0; i < w; i++) {
			if (withinHole(i, j)) continue;
			if (within(i - 1, j))
				if (j == h - 1)
					poss[i][j] += poss[i - 1][j];
				else
					poss[i][j] += poss[i - 1][j] * 0.5;
			if (within(i, j - 1))
				if (i == w - 1)
					poss[i][j] += poss[i][j - 1];
				else
					poss[i][j] += poss[i][j - 1] * 0.5;
			// cout << i << " " << j << " " << poss[i][j] << "\n";
		}
	}
	cout << poss[w - 1][h - 1] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef LOCAL
	const string fileName = "";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
#endif
	if (1) {
		int T;
		cin >> T;
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			cout << "Case #" << caseNum << ": ";
			solve(caseNum);
		}
	} else solve();
	return 0;
}