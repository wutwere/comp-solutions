/*
ID: blitesa1
LANG: C++14
PROG: namenum
*/
#include <bits/stdc++.h>

using namespace std;

const int names = 4617;
string validNames[names];

map<char, int> k = {
	{'A', 2}, {'B', 2}, {'C', 2},
	{'D', 3}, {'E', 3}, {'F', 3},
	{'G', 4}, {'H', 4}, {'I', 4},
	{'J', 5}, {'K', 5}, {'L', 5},
	{'M', 6}, {'N', 6}, {'O', 6},
	{'P', 7}, {'R', 7}, {'S', 7},
	{'T', 8}, {'U', 8}, {'V', 8},
	{'W', 9}, {'X', 9}, {'Y', 9},
};

void solve(int case_num = 0) {
	string serial;
	cin >> serial;
	int slen = serial.length();
	bool none = 1;
	for (int i = 0; i < names; i++) {
		string n = validNames[i];
		int len = n.length();
		if (len != slen) continue;
		bool valid = 1;
		for (int j = 0; j < n.length(); j++) {
			//cout << k[n[j]] << " " << serial[j] - '0' << "\n";
			if (k[n[j]] != (int)serial[j] - '0') {
				valid = 0;
				break;
			}
		}
		if (valid) {
			none = 0;
			cout << n << "\n";
		}
	}
	if (none) cout << "NONE\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	{
		ifstream cin("dict.txt");
		for (int i = 0; i < names; i++) {
			cin >> validNames[i];
		}
	}
	#ifndef TESTING
	const string usaco_file = "namenum";
	if (usaco_file.length()) {
		freopen((usaco_file + ".in").c_str(), "r", stdin);
		freopen((usaco_file + ".out").c_str(), "w", stdout);
	}
	#endif
	solve();
	return 0;
}