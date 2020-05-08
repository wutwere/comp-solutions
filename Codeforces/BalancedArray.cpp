#include <bits/stdc++.h>
using namespace std;

void solve(int caseNum = 0) {
	int n;
	cin >> n;
	n /= 2;
	if (n % 2 == 0) {
		cout << "YES\n";
		for (int i = 1; i <= n; i++) {
			cout << i * 2 << " ";
		}
		for (int i = 1; i <= n / 2; i++) {
			cout << i * 2 - 1 << " ";
		}
		for (int i = n / 2 + 1; i <= n; i++) {
			cout << i * 2 + 1 << " ";
		}
		cout << "\n";
	} else {
		cout << "NO\n";
	}
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