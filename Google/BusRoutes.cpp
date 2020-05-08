#include <bits/stdc++.h>
using namespace std;

void solve(int caseNum = 0) {
	long long n, d;
	cin >> n >> d;
	long long b[n];
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		d = (d / b[i]) * b[i];
	}
	cout << d << "\n";
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