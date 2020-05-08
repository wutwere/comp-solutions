/*
ID: blitesa1
LANG: C++11
PROG: ride
*/
#include <bits/stdc++.h>

using namespace std;

void solve(int case_num = 0) {
	string a, b;
	cin >> a >> b;
	int at = 1, bt = 1;
	for (char c : a) at *= (int)c - 'A' + 1;
	for (char c : b) bt *= (int)c - 'A' + 1;
	cout << (at % 47 == bt % 47 ? "GO" : "STAY") << "\n";
}

int main() {
	const string usaco_file = "ride";
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	if (usaco_file.length()) {
		freopen((usaco_file + ".in").c_str(), "r", stdin);
		freopen((usaco_file + ".out").c_str(), "w", stdout);
	}
	solve();
	return 0;
}