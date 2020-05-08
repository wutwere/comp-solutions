#include <bits/stdc++.h>
using namespace std;

void solve(int caseNum = 0) {
	long long n;
	cin >> n;
	long long fs = (n - 1) / 8;
	n = (n - 1) % 8 + 1;
	long long ans = 0;
	if (n == 1) ans += 1;
	else if (n == 2) ans += 2;
	else if (n == 3) ans += 4;
	else if (n == 4) ans += 7;
	else if (n == 5) ans += 8;
	else if (n == 6) ans += 11;
	else if (n == 7) ans += 13;
	else if (n == 8) ans += 14;
	cout << ans + (fs * 15) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef LOCAL
	const string fileName = "moobuzz";
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