/*
ID: blitesa1
LANG: C++14
PROG: preface
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXL = 7;
pair<int, char> l[MAXL] = {
	{1, 'I'}, {5, 'V'}, {10, 'X'},
	{50, 'L'}, {100, 'C'}, {500, 'D'},
	{1000, 'M'},
};
map<char, int> res;

void count(int num) {
	while (num > 0) {
		for (int i = MAXL - 1; i >= 0; i--) {
			int big = 0;
			if (l[i].first <= num) {
				big = max(big, l[i].first);
			}
			bool a = 0;
			for (int j = 1; j <= 2; j++) {
				int s = i - j;
				int m = l[i].first - l[s].first;
				if (s != 1 && s != 3 && s != 5 && s >= 0 && s < MAXL && m <= num && m > big) {
					res[l[i].second]++;
					res[l[s].second]++;
					num -= m;
					// cerr << l[s].second << l[i].second;
					a = 1;
					break;
				}
			}
			if (big && !a) {
				num -= big;
				res[l[i].second]++;
				// cerr << l[i].second;
				break;
			} else if (a) break;
		}
	}
	// cerr << "\n";
}

void solve(int caseNum = 0) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		count(i);
	}
	for (auto p : l) {
		if (res[p.second]) cout << p.second << " " << res[p.second] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#else
	const string fileName = "preface";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
#endif
	if (0) {
		int T;
		cin >> T;
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			//cout << "Case #" << caseNum << ": ";
			solve(caseNum);
		}
	} else solve();
	return 0;
}