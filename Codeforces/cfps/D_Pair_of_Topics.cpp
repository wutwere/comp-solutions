#include <bits/stdc++.h>

using namespace std;

const bool print_case = 0;
const string usaco_file = "";

void solve(int T) {
	long long a[T][2];
	for (long long i = 0; i < 2; i++)
		for (long long j = 0; j < T; j++)
			cin >> a[j][i];
	long long diffs[T];
	for (long long i = 0; i < T; i++)
		diffs[i] = a[i][0] - a[i][1];
	sort(diffs, diffs + T);
	long long L = 0, R = T - 1, good = 0;
	while (L < R) {
		if (diffs[L] + diffs[R] > 0) {
			good += R - L;
			R--;
		} else L++;
	}
	cout << good;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	if (usaco_file.length()) {
		freopen((usaco_file + ".in").c_str(), "r", stdin);
		freopen((usaco_file + ".out").c_str(), "w", stdout);
	}
	int T;
	cin >> T;
	solve(T);
	return 0;
}