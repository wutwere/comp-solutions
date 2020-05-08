#include <bits/stdc++.h>
using namespace std;

void solve(int caseNum = 0) {
	int n;
	cin >> n;
	int t[n];
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (i != 0 && i != n - 1 && t[i] > t[i - 1] && t[i] > t[i + 1]) {
			res++;
		}
	}
	cout << res << "\n";
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