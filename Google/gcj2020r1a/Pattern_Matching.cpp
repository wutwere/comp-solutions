#include <bits/stdc++.h>

using namespace std;

void solve(int caseNum = 0) {
	int n;
	cin >> n;
	string words[n];
	string longest = "";
	for (int i = 0; i < n; i++) {
		cin >> words[i];
		if (words[i].length() > longest.length()) longest = words[i];
	}
	// go through longest string backwards
	// if its not a *, check if all other strings have it, if not? impossible
	int llen = longest.length();
	string res = "";
	for (int i = 1; i < llen; i++) {
		for (string s : words) {
			int slen = s.length();
			if (slen > i) {
				if (s[slen - i] != longest[llen - i]) {
					cout << "*\n";
					return;
				}
			}
		}
		res = longest[llen - i] + res;
	}
	cout << res << "\n";
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
		cout << "Case #" << caseNum << ": ";
		solve(caseNum);
	}
	return 0;
}