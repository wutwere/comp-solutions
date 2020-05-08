#include <bits/stdc++.h>
using namespace std;

int n;

void solve(int caseNum = 0) {
	int a, b;
	cin >> a >> b;
	if (caseNum == 1)
		cin >> n;
	for (int i = 0; i < n; i++) {
		int guess = ((a + b + 1) / 2);
		cout << guess << "\n";
		cout.flush();
		string s;
		cin >> s;
		if (s == "CORRECT") {
			return;
		} else if (s == "WRONG_ANSWER") {
			exit(0);
		} else if (s == "TOO_BIG") {
			b = guess;
		} else if (s == "TOO_SMALL") {
			a = guess;
		}
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
			// cout << "Case #" << caseNum << ": ";
			solve(caseNum);
		}
	} else solve();
	return 0;
}