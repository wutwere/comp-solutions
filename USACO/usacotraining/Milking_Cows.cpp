/*
ID: blitesa1
LANG: C++11
PROG: milk2
*/
#include <bits/stdc++.h>

using namespace std;

void solve(int case_num = 0) {
	int n;
	cin >> n;
	vector<array<int, 2>> times;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		times.push_back({start, end});
	}
	sort(times.begin(), times.end());
	for (int i = 0; i < n; i++) {
		if (i && times[i][0] <= times[i - 1][1]) {
			times[i][0] = min(times[i][0], times[i - 1][0]);
			times[i][1] = max(times[i - 1][1], times[i][1]);
		}
	}
	int longestOne = 0, longestNone = 0;
	for (int i = 0; i < n; i++) {
		//cout << times[i][0] << " " << times[i][1] << "\n";
		longestOne = max(longestOne, times[i][1] - times[i][0]);
		if (i) longestNone = max(longestNone, times[i][0] - times[i - 1][1]);
	}
	cout << longestOne << " " << longestNone << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef TESTING
	const string usaco_file = "milk2";
	if (usaco_file.length()) {
		freopen((usaco_file + ".in").c_str(), "r", stdin);
		freopen((usaco_file + ".out").c_str(), "w", stdout);
	}
	#endif
	solve();
	return 0;
}