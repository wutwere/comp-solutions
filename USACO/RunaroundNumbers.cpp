/*
ID: blitesa1
LANG: C++14
PROG: runround
*/
#include <bits/stdc++.h>
using namespace std;

bool isGood(int num) {
	vector<int> d;
	bool taken[10];
	memset(taken, 0, sizeof(taken));
	while (num > 0) {
		int dig = num % 10;
		if (taken[dig] || dig == 0) return 0;
		else taken[dig] = 1;
		num -= dig;
		num /= 10;
		d.push_back(dig);
	}
	int ds = d.size();
	int good = ds - 1;
	if (taken[ds]) return 0;
	reverse(d.begin(), d.end());
	memset(taken, 0, sizeof(taken));
	int cur = d[0] % ds;
	taken[d[cur]] = 1;
	while (cur != 0) {
		cur = (cur + d[cur]) % ds;
		if (taken[d[cur]]) return 0;
		taken[d[cur]] = 1;
		good--;
	}
	return !good;
}

void solve(int caseNum = 0) {
	int m;
	cin >> m;
	for (int i = m + 1; i < 1e7; i++) {
		if (isGood(i)) {
			cout << i << "\n";
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// freopen("error.txt", "w", stderr);
#else
	const string fileName = "runround";
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