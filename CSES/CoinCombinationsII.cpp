#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<long long> coins(n), ways(x + 1);
	fill(ways.begin(), ways.end(), 0);
	ways[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	for (int j = 0; j < n; j++) {
		for (int i = 1; i <= x; i++) {
			if (i - coins[j] >= 0) {
				(ways[i] += ways[i - coins[j]]) %= (int) 1e9 + 7;
			}
		}
	}
	cout << ways[x] << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}