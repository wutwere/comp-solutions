#include <bits/stdc++.h>
using namespace std;

string names[8] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};

int n;
map<string, string> m;
unordered_set<string> already;
vector<string> final;

void addStrs(string a, string b) {
	if (a < b) {
		if (m.count(a)) {
			if (b > m[a]) {
				string c = m[a];
				m[a] = b;
				addStrs(a, c);
			} else {
				m[b] = a;
			}
		} else {
			m[a] = b;
		}
	} else {
		addStrs(b, a);
	}
}

void printName(string nm, string& s, bool org = 1) {
	if (!already.count(nm)) {
		already.insert(nm);
		for (auto p : m) {
			if (p.second == nm) {
				printName(p.first, s, 0);
				break;
			}
		}
		s = s + nm + "\n";
		if (m.count(nm)) {
			printName(m[nm], s, 0);
		}
		if (org) final.push_back(s);
	}
}

void solve(int caseNum = 0) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		addStrs(a, f);
	}
	sort(names, names + 8);
	for (int i = 0; i < 8; i++) {
		string s = "";
		printName(names[i], s);
	}
	sort(final.begin(), final.end());
	for (string s : final) {
		cout << s;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef LOCAL
	const string fileName = "lineup";
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