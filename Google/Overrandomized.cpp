#include <bits/stdc++.h>
using namespace std;

void solve() {
	int u;
	cin >> u;
	map<int, map<char, bool>> poss;
	for (int i = 0; i < 10000; i++) {
		string q, r;
		cin >> q >> r;
		int qlen = q.length();
		int len = r.length();
		for (int j = 0; j < len; j++) {
			int maxD = q[j] - '0';
			if (j == 0 && len != 1) {
				poss[0][r[j]] = 0;
				for (int k = 1; k <= maxD; k++) {
					if (!poss[k].count(r[j])) {
						poss[k][r[j]] = 1;
					}
				}
				for (int k = maxD + 1; k < 10; k++) {
					poss[k][r[j]] = 0;
				}
			} else if (j == 0 && len == 1 && qlen == 1) {
				for (int k = 0; k <= maxD; k++) {
					if (!poss[k].count(r[j])) {
						poss[k][r[j]] = 1;
					}
				}
				for (int k = maxD + 1; k < 10; k++) {
					poss[k][r[j]] = 0;
				}
			} else {
				for (int k = 0; k < 10; k++) {
					if (!poss[k].count(r[j])) {
						poss[k][r[j]] = 1;
					}
				}
			}
		}
	}
	map<char, bool> used;
	for (auto p : poss[0]) {
		if (p.second) {
			used[p.first] = 1;
			cout << p.first;
			break;
		}
	}
	string s = "";
	for (int i = 9; i >= 1; i--) {
		for (auto p : poss[i]) {
			if (p.second && !used.count(p.first)) {
				used[p.first] = 1;
				s = p.first + s;
				break;
			}
		}
	}
	cout << s << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}