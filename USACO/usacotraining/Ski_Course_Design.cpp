/*
ID: blitesa1
LANG: C++14
PROG: skidesign
*/
#include <bits/stdc++.h>

using namespace std;

void solve(int caseNum = 0) {
	int n;
	cin >> n;
	int hills[n];
	int lowest = 1e9, highest = 0;
	for (int i = 0; i < n; i++) {
		cin >> hills[i];
		lowest = min(lowest, hills[i]);
		highest = max(highest, hills[i]);
	}
	if (highest - lowest <= 17) {
		cout << "0\n";
		return;
	}
	int lowestCost = 1e9;
	for (int i = lowest; i < highest - 17; i++) {
		int cost = 0;
		for (int j = 0; j < n; j++) {
			if (hills[j] < i) cost += (i - hills[j]) * (i - hills[j]);
			else if (hills[j] > i + 17) cost += (hills[j] - i - 17) * (hills[j] - i - 17);
		}
		lowestCost = min(cost, lowestCost);
	}
	cout << lowestCost << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef TESTING
	const string fileName = "skidesign";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
	#endif
	solve();
	return 0;
}