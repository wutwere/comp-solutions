/*
ID: blitesa1
LANG: C++14
PROG: zerosum
*/

#include <bits/stdc++.h>
using namespace std;

int n;
string s('.', 8);
vector<string> res;

void dfs(char op, int step) {
	s[step] = op;
	if (step == n - 2) {
		vector<int> nums;
		nums.push_back(1);
		int last = 0;
		for (int i = 2; i <= n; i++) {
			if (s[i - 2] == '+') {
				nums.push_back(i);
				last++;
			} else if (s[i - 2] == '-') {
				nums.push_back(-i);
				last++;
			} else {
				nums[last] *= 10;
				if (nums[last] > 0) nums[last] += i;
				else nums[last] -= i;
			}
		}
		if (accumulate(nums.begin(), nums.end(), 0) == 0) {
			string ans = "1";
			for (int i = 2; i <= n; i++) {
				ans += s[i - 2];
				ans += i + '0';
			}
			res.push_back(ans);
		}
	} else {
		dfs('+', step + 1);
		dfs('-', step + 1);
		dfs(' ', step + 1);
	}
}

void solve(int caseNum = 0) {
	cin >> n;
	dfs('+', 0);
	dfs('-', 0);
	dfs(' ', 0);
	sort(res.begin(), res.end());
	for (string ans : res) {
		cout << ans << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef LOCAL
	const string fileName = "zerosum";
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
