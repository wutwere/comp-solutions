#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	for (int ii = 1; ii <= t; ii++) {
		int n;
		cin >> n;
		int grid[n][n];
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				int m;
				cin >> m;
				grid[x][y] = m;
			}
		}
		int k = 0;
		int repeatr = 0;
		int repeatc = 0;
		for (int i = 0; i < n; i++) {
			k += grid[i][i];
			set<int> prevR;
			set<int> prevC;
			bool isrr = 0, isrc = 0;
			for (int j = 0; j < n; j++) {
				if (prevR.count(grid[i][j])==0) {prevR.insert(grid[i][j]);}
				else isrr = 1;
				if (prevC.count(grid[j][i])==0) prevC.insert(grid[j][i]);
				else isrc = 1;
			}
			repeatr += isrr;
			repeatc += isrc;
		}
		cout << "Case #" << ii << ": " << k << " " << repeatc << " " << repeatr << "\n";
	}
	return 0;
}
