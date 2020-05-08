/*
ID: blitesa1
LANG: C++14
PROG: barn1
*/
#include <bits/stdc++.h>

using namespace std;

void solve(int caseNum = 0) {
	int boards, stalls, cows;
	cin >> boards >> stalls >> cows;
	int occupied[cows], gaps[cows - 1];
	int low = 1e9, high = 0;
	for (int i = 0; i < cows; i++) {
		cin >> occupied[i];
		low = min(low, occupied[i]);
		high = max(high, occupied[i]);
	}
	sort(occupied, occupied + cows);
	for (int i = 0; i < cows - 1; i++) {
		gaps[i] = occupied[i + 1] - occupied[i] - 1;
	}
	sort(gaps, gaps + cows - 1);
	boards--;
	stalls = high - low + 1;
	for (int i = cows - 2; boards > 0 && i >= 0; i--) {
		if (gaps[i] > 0) {
			boards--;
			stalls -= gaps[i];
		} else break;
	}
	cout << stalls << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef TESTING
	const string fileName = "barn1";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
	#endif
	solve();
	return 0;
}