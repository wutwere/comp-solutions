#include <bits/stdc++.h>

using namespace std;

void solve(int caseNum = 0) {
	int n, a, b;
	cin >> n >> a >> b;
	string s = "";
	for (int i = 0; i < n; i++) {
		s += (i % b) + 'a';
	}
	cout << s << "\n";
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