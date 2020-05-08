#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	if (n == 2 || n == 3) {
		cout << "NO SOLUTION\n";
		return;
	}
	if (n == 4) {
		cout << "2 4 1 3\n";
		return;
	}
	int nums[n];
	for (int i = 0; i < n; i++) {
		nums[i] = i * 2 % n + 1 + (n % 2 == 0 && i >= n / 2);
		cout << nums[i] << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}