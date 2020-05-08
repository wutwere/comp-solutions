#include <bits/stdc++.h>
using namespace std;

void solve(int caseNum = 0) {
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	int l = c - d, u = c + d;
	bool good = 0;
	for (int i = n * (a - b); i <= n * (a + b); i++) {
		if (i >= l && i <= u) {
			good = 1;
			break;
		}
	}
	cout << (good ? "Yes" : "No") << "\n";
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
			//cout << "Case #" << caseNum << ": ";
			solve(caseNum);
		}
	} else solve();
	return 0;
}

