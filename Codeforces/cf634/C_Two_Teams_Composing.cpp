#include <bits/stdc++.h>

using namespace std;

void solve(int caseNum = 0) {
	int n;
	cin >> n;
	unordered_set<int> unique;
	unordered_multiset<int> rep;
	map<int, int> uc;
	map<int, int> rc;
	int last = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (unique.count(a) == 0) {
			unique.insert(a);
			uc[a]++;
			last = a;
		} else {
			rep.insert(a);
			rc[a]++;
		}
	}
	int resu = 0;
	if (last && rep.size() == 0) {
		unique.erase(last);
		uc[last]--;
		rep.insert(last);
		rc[last]++;
	}
	int usize = unique.size();
	for (int i : rep) {
		int c = rc[i];
		int teams = min(usize, c);
		resu = max(resu, teams);
		if (uc[i]) {
			teams = min(usize - 1, c + 1);
			resu = max(resu, teams);
		}
	}
	cout << resu << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef TESTING
	const string fileName = "";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
	#endif
	int T;
	cin >> T;
	for (int caseNum = 1; caseNum <= T; caseNum++) {
		//cout << "Case #" << caseNum << ": ";
		solve(caseNum);
	}
	return 0;
}