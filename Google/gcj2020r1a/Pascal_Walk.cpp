#include <bits/stdc++.h>

using namespace std;

void solve(int caseNum = 0) {
	int n;
	cin >> n;
	cout << "\n";
	if (n == 501) {
		cout << "1 1\n";
		cout << "2 2\n";
		cout << "3 2\n";
		for (int i = 3; i <= 499; i++) {
			cout << i << " 1\n";
		}
	} else {
		for (int i = 1; i <= n; i++) {
			cout << i << " 1\n";
		}
	}
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
		cout << "Case #" << caseNum << ": ";
		solve(caseNum);
	}
	return 0;
}