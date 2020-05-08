#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, x, w = 0, k = 0, ans = 0;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		w += p;
		if (w >= x || k >= 2) {
			ans++;
			w = 0;
			
		}
	}
	if (sum) {
		ans++;
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}