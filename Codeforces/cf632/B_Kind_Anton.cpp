#include <bits/stdc++.h>

using namespace std;

void solve(int caseNum = 0) {
	int n;
	cin >> n;
	int a[n], b[n];
	for (int j = 0; j < n; j++) cin >> a[j];
	for (int j = 0; j < n; j++) cin >> b[j];
	bool neg = 0, z = 0, p = 0;
	if (a[0] < 0) neg = 1;
	else if (a[0] == 0) z = 1;
	else if (a[0] > 0) p = 1;
	bool poss = a[0] == b[0];
	for (int j = 1; j < n; j++) {
		if (b[j] < a[j]) {
			if (!neg) poss = 0;
		//} else if (b[j] == a[j]) {
		//	if (!z) poss = 0;
		} else if (b[j] > a[j]) {
			if (!p) poss = 0;
		}
		if (a[j] < 0) neg = 1;
		else if (a[j] == 0) z = 1;
		else if (a[j] > 0) p = 1;
	}
	cout << (poss ? "YES" : "NO") << "\n";
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
		//cout << "Case #" << caseNum << ": ";
		solve(caseNum);
	}
	return 0;
}