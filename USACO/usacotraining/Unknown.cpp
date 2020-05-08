/*
ID: blitesa1
LANG: C++11
PROG: gift1
*/
#include <bits/stdc++.h>

using namespace std;

void solve(int case_num = 0) {
	int np;
	cin >> np;
	map<string, int> balance;
	string nameOrder[np];
	for (int i = 0; i < np; i++) {
		string name;
		cin >> name;
		balance[name] = 0;
		nameOrder[i] = name;
	}
	while (np--) {
		string name;
		cin >> name;
		int money, div;
		cin >> money >> div;
		int give = 0;
		if (div != 0) give = money / div;
		//balance[name] += money - give * div;
		while (div--) {
			string rec;
			cin >> rec;
			balance[rec] += give;
			balance[name] -= give;
		}
	}
	for (auto name : nameOrder) {
		cout << name << " " << balance[name] << "\n";
	}
}

int main() {
	const string usaco_file = "gift1";
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	if (usaco_file.length()) {
		freopen((usaco_file + ".in").c_str(), "r", stdin);
		freopen((usaco_file + ".out").c_str(), "w", stdout);
	}
	solve();
	return 0;
}