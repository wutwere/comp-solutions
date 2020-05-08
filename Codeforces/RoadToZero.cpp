#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long x, y, a, b;
	cin >> x >> y >> a >> b;
	if (b < a * 2) {
		cout << b * min(x, y) + a * (max(x, y) - min(x, y)) << "\n";
	} else {
		cout << a * (x + y) << "\n";
	}
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

