/*
ID: blitesa1
LANG: C++14
PROG: combo
*/
#include <bits/stdc++.h>

using namespace std;

void solve(int caseNum = 0) {
	int n, fj1, fj2, fj3, ma1, ma2, ma3;
	cin >> n >> fj1 >> fj2 >> fj3 >> ma1 >> ma2 >> ma3;
	map<int, map<int, map<int, bool>>> used;
	int combos = 0;
	for (int i = -2; i <= 2; i++) {
		for (int j = -2; j <= 2; j++) {
			for (int k = -2; k <= 2; k++) {
				if (!used[(fj1 + i + n) % n][(fj2 + j + n) % n][(fj3 + k + n) % n]) {
					used[(fj1 + i + n) % n][(fj2 + j + n) % n][(fj3 + k + n) % n] = 1;
					combos++;
				}
				if (!used[(ma1 + i + n) % n][(ma2 + j + n) % n][(ma3 + k + n) % n]) {
					used[(ma1 + i + n) % n][(ma2 + j + n) % n][(ma3 + k + n) % n] = 1;
					combos++;
				}
			}
		}
	}
	cout << combos << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef TESTING
	const string fileName = "combo";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
	#endif
	solve();
	return 0;
}