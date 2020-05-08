#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long y, x;
	cin >> y >> x;
	if (x > y)
		if (x % 2) cout << x * x - y + 1 << "\n";
		else cout << (x - 1) * (x - 1) + y << "\n";
	else
		if (y % 2 == 0) cout << y * y - x + 1 << "\n";
		else cout << (y - 1) * (y - 1) + x << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}