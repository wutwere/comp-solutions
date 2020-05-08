#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	bool hasZ = 0, hasO = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') {
			hasZ = 1;
		} else if (s[i] == '1') {
			hasO = 1;
		}
	}
	if (hasZ && hasO) {
		int len = s.length() * 2;
		for (int i = 0; i < len; i++) {
			if (i + 1 >= s.length()) {
				break;
			}
			if (s[i + 1] == s[i]) {
				char ins;
				if (s[i] == '1') {
					ins = '0';
				} else {
					ins = '1';
				}
				s.insert(s.begin() + i + 1, ins);
			}
		}
		cout << s << "\n";
	} else {
		cout << s << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}

