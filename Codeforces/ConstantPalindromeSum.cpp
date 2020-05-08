#include <bits/stdc++.h>
using namespace std;

void solve(int caseNum = 0) {
	int n, k;
	cin >> n >> k;
	int nums[n + 1];
	map<int, int> count;
	map<int, vector<int>> sums;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
		if (i >= n / 2 + 1) {
			sums[nums[n - i + 1] + nums[i]].push_back(nums[i]);
			count[nums[n - i + 1] + nums[i]]++;
		}
	}
	int ans = 1e9;
	for (auto p : count) {
		int s = p.first;
		int c = p.second;
		int changes = n / 2 - c;
		for (auto p2 : sums) {
			if (p2.first != s) {
				int diff = abs(s - p2.first);
				for (auto num : p2.second) {
					// cout << diff << " " << num << "\n";
					bool check1 = num - diff >= 1 && (s - num) + diff <= k;
					bool check2 = (s - num) - diff >= 1 && num + diff <= k;
					if (!(check1 || check2))
						changes++;
				}
			}
		}
		// cout << changes << "\n";
		ans = min(ans, changes);
	}
	cout << ans << "\n";
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
			//cout << "Case #" << caseNum << ": ";
			solve(caseNum);
		}
	} else solve();
	return 0;
}