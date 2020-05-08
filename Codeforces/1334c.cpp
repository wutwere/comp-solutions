#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	long long h[n];
	long long d[n];
	long long minb = 0, ans = 1e18;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		cin >> d[i];
		if (i && h[i] - d[i - 1] > 0) {
			minb += h[i] - d[i - 1];
		}
	}
	if (h[0] - d[n - 1] > 0)
		minb += h[0] - d[n - 1];
	for (int i = 0; i < n; i++) {
		ans = min(ans, minb + min(h[i], d[(i - 1 + n) % n]));
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

