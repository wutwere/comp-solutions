#include <bits/stdc++.h>

using namespace std;

void solve(int caseNum = 0) {
	int n;
	cin >> n;
	int lens[n][2];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			lens[i][j] = 0;
		}
	}
	for (int i = 0, j = 0; i < n; i++) {
		int a;
		cin >> a;
		if (!(lens[j][0] == a || lens[j][1] == 0)) {
			j++;
		}
		lens[j][0] = a;
		lens[j][1]++;
	}
	int res = 0;
	map<int, int> prevlens;
	for (int i = 0; i < n; i++) {
		if (lens[i][0] == 0) break;
		res = max(res, lens[i][1]);
		for (int j = i + 1; j < n; j++) {
			if (lens[j][0] == 0) break;
			if (lens[i][0] == lens[j][0]) {
				map<int, int> midlens;
				int biggest = 0;
				for (int k = i + 1; k < j; k++) {
					midlens[lens[k][0]] += lens[k][1];
					biggest = max(biggest, midlens[lens[k][0]]);
				}
				int exlens = 0;
				for (int k = j + 1; k < n; k++) {
					if (lens[j][0] == lens[k][0]) {
						exlens += lens[k][1];
					}
				}
				res = max(res, min(lens[i][1] + prevlens[lens[i][0]], lens[j][1] + exlens) * 2 + biggest);
			}
		}
		prevlens[lens[i][0]] += lens[i][1];
	}
	cout << res << "\n";
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