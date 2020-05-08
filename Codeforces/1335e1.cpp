#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> nums(n);
	map<int, map<int, int>> mcount;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		mcount[i][nums[i]]++;
		for (auto p : mcount[i]) {
			mcount[i + 1][p.first] += p.second;
		}
	}
	vector<pair<int, int>> count;
	for (auto p : mcount[n]) {
		count.push_back({p.second, p.first});
	}
	sort(count.begin(), count.end());
	int ans = count[count.size() - 1].first;
	for (int i = count.size() - 1; i >= 0; i--) {
		for (int j = count.size() - 1; j >= 0; j--) {
			if (i != j && count[i].first + count[j].first > ans) {
				int L = -1, R = n, ic = 2;
				while (++L < n) if (nums[L] == count[i].second) break;
				while (--R >= 0) if (nums[R] == count[i].second) break;
				while (L < R) {
					int jc = mcount[R - 1][count[j].second] - mcount[L][count[j].second];
					ans = max(ans, ic + jc);
					while (++L < n) if (nums[L] == count[i].second) break;
					while (--R >= 0) if (nums[R] == count[i].second) break;
					ic += 2;
				}
			}
		}
	}
	cout << ans << "\n";
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

