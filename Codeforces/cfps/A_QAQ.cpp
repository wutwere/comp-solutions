#include <bits/stdc++.h>

using namespace std;

void solve(int case_num = 0) {
	string s;
	cin >> s;
	int dp[s.length()];
	// s = "QAQAQ"
	// dp[0] = 0, dp[1] = 0, dp[2] = 1, dp[3] = 1, dp[4] = 4
	dp[0] = 0;
	for (int i = 1; i < s.length(); i++) {
		int add = 0;
		if (s[i] == 'Q') {
			int as = 0;
			for (int j = i - 1; j >= 0; j--) {
				if (s[j] == 'A') as++;
				else if (s[j] == 'Q') add += as;
			}
		}
		dp[i] = dp[i - 1] + add;
	}
	cout << dp[s.length() - 1];
}

int main() {
	const string usaco_file = "";
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	if (usaco_file.length()) {
		freopen((usaco_file + ".in").c_str(), "r", stdin);
		freopen((usaco_file + ".out").c_str(), "w", stdout);
	}
	solve();
	return 0;
}