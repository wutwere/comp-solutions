#include <bits/stdc++.h>
using namespace std;

const long long fbil = 1e10;
const long long bil = 1e9;

pair<char, pair<long long, long long>> dirs[4] = {
	{'N', {0, -1}}, {'S', {0, 1}}, {'E', {1, 0}}, {'W', {-1, 0}}
};

void solve(int caseNum = 0) {
	string s;
	cin >> s;
	int i = 0;
	long long x = 1, y = 1;
	vector<long long> muls;
	long long mult = 1;
	while (i < s.length()) {
		char c = s[i];
		if (c == ')') {
			mult /= muls[muls.size() - 1];
			muls.pop_back();
		} else {
			bool isNum = 1;
			for (auto p : dirs) {
				if (p.first == c) {
					isNum = 0;
					x += p.second.first * mult;
					y += p.second.second * mult;
				}
			}
			if (isNum) {
				long long num = c - '0';
				mult *= num;
				muls.push_back(num);
				i++;
			}
		}
		i++;
	}
	while (x < 0) x = (x - 1 + fbil) % bil + 1;
	while (y < 0) y = (y - 1 + fbil) % bil + 1;
	cout << x << " " << y << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef LOCAL
	const string fileName = "";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
#endif
	if (1) {
		int T;
		cin >> T;
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			cout << "Case #" << caseNum << ": ";
			solve(caseNum);
		}
	} else solve();
	return 0;
}