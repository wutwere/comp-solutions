#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int nums[n];
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		if (i && nums[i - 1] > nums[i]) {
			ans += nums[i - 1] - nums[i];
			nums[i] = nums[i - 1];
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}