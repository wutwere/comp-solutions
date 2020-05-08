#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int t = 0;
	for (int i = 1; i < n; i++) {
		if (nums[i] < nums[i - 1]) {
			string need = bitset<32>(nums[i - 1] - nums[i]).to_string();
			int highest;
			for (int i = 0; i < 32; i++) {
				if (need[i] == '1') {
					highest = 32 - i;
					break;
				}
			}
			t = max(t, highest);
			nums[i] = nums[i - 1];
		}
	}
	cout << t << "\n";
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