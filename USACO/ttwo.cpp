/*
ID: blitesa1
LANG: C++14
PROG: ttwo
*/

#include <bits/stdc++.h>
using namespace std;

pair<int, int> dirs[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

void solve() {
	string grid[10];
	int fsx, fsy, csx, csy;
	for (int i = 0; i < 10; i++) {
		cin >> grid[i];
		for (int j = 0; j < 10; j++) {
			if (grid[i][j] == 'F') {
				fsx = j;
				fsy = i;
				grid[i][j] = '.';
				break;
			} else if (grid[i][j] == 'C') {
				csx = j;
				csy = i;
				grid[i][j] = '.';
				break;
			}
		}
	}
	int fx = fsx, fy = fsy, cx = csx, cy = csy;
	int fd = 0, cd = 0;
	for (int i = 0; i < 10000000; i++) {
		int nfx = fx + dirs[fd].first;
		int nfy = fy + dirs[fd].second;
		if (nfx < 0 || nfx >= 10 || nfy < 0 || nfy >= 10 || grid[nfy][nfx] == '*') {
			fd++;
			fd %= 4;
		} else {
			fx = nfx;
			fy = nfy;
		}
		int ncx = cx + dirs[cd].first;
		int ncy = cy + dirs[cd].second;
		if (ncx < 0 || ncx >= 10 || ncy < 0 || ncy >= 10 || grid[ncy][ncx] == '*') {
			cd++;
			cd %= 4;
		} else {
			cx = ncx;
			cy = ncy;
		}
		if (fx == cx && fy == cy) {
			cout << i + 1 << "\n";
			return;
		}
	}
	cout << "0\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifndef LOCAL
	freopen("ttwo.in", "r", stdin);
	freopen("ttwo.out", "w", stdout);
#endif
	solve();
	return 0;
}

