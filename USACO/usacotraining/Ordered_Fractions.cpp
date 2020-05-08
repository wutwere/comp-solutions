/*
ID: blitesa1
LANG: C++14
PROG: frac1
*/
#include <bits/stdc++.h>

using namespace std;

void solve(int caseNum = 0) {
	int n;
	cin >> n;
	vector<pair<double, string>> all;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			bool good = 1;
			for (int k = 0; k < all.size(); k++) {
				if (abs(all[k].first - (double)j/i) < 0.0000000001) {
					good = 0;
					break;
				}
			}
			if (good) all.push_back({(double)j/i, to_string(j) + "/" + to_string(i)});
		}
	}
	sort(all.begin(), all.end());
	for (int i = 0; i < all.size(); i++) {
		cout << all[i].second << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef TESTING
	const string fileName = "frac1";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
	#endif
	solve();
	return 0;
}