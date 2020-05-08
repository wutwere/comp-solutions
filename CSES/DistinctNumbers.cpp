#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, ans = 1;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	sort(nums, nums + n);
	for (int i = 1; i < n; i++)
		if (nums[i] != nums[i - 1])
			ans++;
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}