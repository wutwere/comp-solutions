#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long n;
	cin >> n;
	int ans = 0;
	while (n > 1) {
		for (long long i = 100000; i > 0; i--) {
			long long cards = i * (i + 1) + i * (i - 1) / 2;
			if (cards <= n) {
				ans++;
				n -= cards;
				// cout << "debug " << cards << " " << n << "\n";
				break;
			}
		}
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