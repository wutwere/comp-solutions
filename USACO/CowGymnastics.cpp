#include <bits/stdc++.h>
using namespace std;

void solve(int caseNum = 0) {
	int k, n;
	cin >> k >> n;
	int rank[k][n + 1];
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			int cow;
			cin >> cow;
			rank[i][cow] = j;
		}
	}
	int pairs = 0;
	for (int cow1 = 1; cow1 <= n; cow1++) {
		for (int cow2 = 1; cow2 <= n; cow2++) {
			bool good = 1;
			for (int i = 0; i < k; i++) {
				if (rank[i][cow1] <= rank[i][cow2]) {
					good = 0;
					break;
				}
			}
			pairs += good;
		}
	}
	cout << pairs << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef LOCAL
	const string fileName = "gymnastics";
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