/*
ID: blitesa1
LANG: C++11
PROG: beads
*/
#include <bits/stdc++.h>

using namespace std;

void solve(int case_num = 0) {
	int len, c1 = 0, c2 = 0, most = 0, ws = 0;
	string s;
	cin >> len >> s;
	char col = s[0];
	for (int i = 0; i < len * 2; i++) {
		int ind = i % len;
		if (s[ind] != 'w' && s[ind] != col) {
			most = max(most, c1 + c2);
			c1 = c2 - ws;
			c2 = ws;
			col = s[ind];
		}
		if (c1 + c2 == len) {
			most = len;
			break;
		}
		if (s[ind] == 'w') ws++;
		else ws = 0;
		c2++;
		//cout << s[ind] << " " << c2 << "\n";
	}
	cout << most << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	const string usaco_file = "beads";
	if (usaco_file.length()) {
		freopen((usaco_file + ".in").c_str(), "r", stdin);
		freopen((usaco_file + ".out").c_str(), "w", stdout);
	}
	solve();
	return 0;
}