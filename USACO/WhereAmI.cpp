#include <bits/stdc++.h>
using namespace std;

void solve(int caseNum = 0) {
	int n;
	string s;
	cin >> n >> s;
	int k;
	unordered_set<string> taken;
	for (k = n; k >= 1; k--) {
		taken.clear();
		bool good = 1;
		for (int i = 0; i <= n - k; i++) {
			string sub = s.substr(i, k);
			// cout << sub << "\n";
			if (taken.count(sub)) {
				good = 0;
				break;
			}
			taken.insert(sub);
		}
		if (!good) break;
	}
	cout << k + 1 << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef LOCAL
	const string fileName = "whereami";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
#endif
	if (0) {
		int T;
		cin >> T;
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			//cout << "Case #" << caseNum << ": ";
			solve(caseNum);
		}
	} else solve();
	return 0;
}