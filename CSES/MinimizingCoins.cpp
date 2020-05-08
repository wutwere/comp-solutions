#include <bits/stdc++.h>
using namespace std;

long long INF = 1e18;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<long long> coins(n), amt(x + 1);
	amt[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	for (int i = 1; i <= x; i++) {
		amt[i] = INF;
		for (int j = 0; j < n; j++) {
			if (i - coins[j] >= 0) {
				amt[i] = min(amt[i], amt[i - coins[j]] + 1);
			}
		}
		// cout << amt[i] << "\n";
	}
	cout << (amt[x] == INF ? -1 : amt[x]) << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}