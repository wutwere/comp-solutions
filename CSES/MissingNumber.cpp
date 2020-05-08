#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int ans = n;
	for (int i = 1; i < n; i++) {
		int a;
		cin >> a;
		ans += i - a;
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}