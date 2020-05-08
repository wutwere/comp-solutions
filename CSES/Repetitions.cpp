#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	int len = 1;
	int maxlen = 1;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == s[i - 1]) {
			len++;
		} else {
			len = 1;
		}
		maxlen = max(maxlen, len);
	}
	cout << maxlen << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}