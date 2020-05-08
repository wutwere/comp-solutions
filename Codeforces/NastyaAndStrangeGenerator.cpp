#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int nums[n];
	bool good = 1;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		if (i && nums[i] > nums[i - 1] + 1) {
			good = 0;
		}
	}
	cout << (good ? "Yes" : "No") << "\n";
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

