#include <bits/stdc++.h>
using namespace std;

void solve(int caseNum = 0) {
	int n;
	cin >> n;
	for (int k = 30; k >= 1; k--) {
		int num = pow(2, k) - 1;
		if (n % num == 0) {
			cout << (n / num) << "\n";
			break;
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
			//cout << "Case #" << caseNum << ": ";
			solve(caseNum);
		}
	} else solve();
	return 0;
}