#include <bits/stdc++.h>

using namespace std;

void solve(int caseNum = 0) {
	int n;
	cin >> n;
	vector<array<long long, 2>> mons(n);
	vector<long long> hurtmons(n);
	for (int i = 0; i < n; i++) {
		cin >> mons[i][0] >> mons[i][1];
		if (i) hurtmons[i] = mons[i][0] - mons[i - 1 + n % n][1];
	}
	hurtmons[0] = mons[0][0] - mons[n - 1][1];
	long long lowest = LONG_LONG_MAX;
	for (int i = 0; i < n; i++) {
		long long bullets = mons[i][0];
		for (int j = i + 1; j < n + i; j++) {
			//cout << j << " " << hurtmons[i % n] << "\n";
			if (hurtmons[j % n] > 0) bullets += hurtmons[j % n];
			if (bullets >= lowest) break;
		}
		lowest = min(lowest, bullets);
	}
	cout << lowest << "\n";
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