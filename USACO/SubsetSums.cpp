/*
ID: blitesa1
LANG: C++14
PROG: subset
*/
#include <bits/stdc++.h>
using namespace std;

int n;
int totSum = 0;

void solve(int caseNum = 0) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		totSum += i;
	}
	if (totSum % 2 == 0) {
		totSum /= 2;
		long long ways[totSum + 1];
		memset(ways, 0, sizeof(ways));
		ways[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = totSum; j >= i; j--) {
				ways[j] += ways[j - i];
			}
		}
		cout << ways[totSum] / 2 << "\n";
	} else {
		cout << "0\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef LOCAL
	const string fileName = "subset";
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