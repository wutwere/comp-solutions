/*
ID: blitesa1
LANG: C++14
PROG: lamps
*/
#include <bits/stdc++.h>
using namespace std;

#define bset bitset<100>

int n, c;
bset onNum, offNum, full, even, odd, threes;
unordered_set<bset> already;
vector<bset> res;

void dfs(bset num, int steps = 0) {
	bset on = num & onNum;
	bset off = num & offNum;
	bool alr = already.count(num);
	already.insert(num);
	if (on == onNum && off == 0 && !alr) {
		res.push_back(num);
	}
	if (!alr) if (steps < c) {
		dfs(num ^ full, steps + 1);
		dfs(num ^ even, steps + 1);
		dfs(num ^ odd, steps + 1);
		dfs(num ^ threes, steps + 1);
	}
}

bool comp(bset a, bset b) {
	for (int i = 0; i < 100; i++) {
		if (a[i] != b[i]) {
			return a[i] < b[i];
		}
	}
	return 0;
}

void solve(int caseNum = 0) {
	cin >> n >> c;
	while (1) {
		int l;
		cin >> l;
		if (l == -1)
			break;
		onNum.set(l - 1, 1);
	}
	while (1) {
		int l;
		cin >> l;
		if (l == -1)
			break;
		offNum.set(l - 1, 1);
	}
	for (int i = 0; i < n; i++) {
		full.set(i, 1);
	}
	for (int i = 0; i < n; i += 2) {
		odd.set(i, 1);
	}
	for (int i = 1; i < n; i += 2) {
		even.set(i, 1);
	}
	for (int i = 0; i < n; i += 3) {
		threes.set(i, 1);
	}
	dfs(full);
	sort(res.begin(), res.end(), comp);
	bool impossible = 1;
	for (auto i : res) {
		impossible = 0;
		string s(i.to_string(), 100 - n, n);
		reverse(s.begin(), s.end());
		cout << s << "\n";
	}
	if (impossible) cout << "IMPOSSIBLE\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef LOCAL
	const string fileName = "lamps";
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