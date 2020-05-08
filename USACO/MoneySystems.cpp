/*
ID: blitesa1
LANG: C++14
PROG: money
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long waysa[10001];
	fill(waysa, waysa + 10001, 0);
	waysa[0] = 1;
	long long coins[25];
	long long v, n;
	cin >> v >> n;
	for (long long i = 0; i < v; i++) {
		cin >> coins[i];
	}
	auto ways = [&](long long num) {
		if (num >= 0) {
			return waysa[num];
		}
		return (long long) 0;
	};
	for (long long i = 0; i < v; i++) {
		for (long long j = 1; j <= n; j++) {
			waysa[j] += ways(j - coins[i]);
		}
	}
	cout << ways(n) << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// freopen("money.in", "r", stdin);
	// freopen("money.out", "w", stdout);
	solve();
	return 0;
}

