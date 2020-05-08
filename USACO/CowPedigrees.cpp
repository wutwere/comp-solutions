/*
ID: blitesa1
LANG: C++14
PROG: nocows
*/

#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

void solve() {
	ll N, K;
	cin >> N >> K;
	ll sols[K + 1][N + 1];
	map<ll, ll> bottoms[K + 1][N + 1];
	memset(sols, 0, sizeof(sols));
	sols[1][1] = 1;
	bottoms[1][1][1] = 1;
	for (ll h = 2; h <= K; h++) {
		for (ll n = 3; n <= N; n += 2) {
			for (ll othern = 1; othern < n; othern += 2) {
				for (auto p : bottoms[h - 1][othern]) {
					if (p.first >= (n - othern) / 2) {
						ll unique = 1;
						for (ll i = 0; i < (n - othern) / 2; i++) {
							unique *= p.first - i;
							unique /= i + 1;
						}
						sols[h][n] += unique * p.second;
						sols[h][n] %= 9901;
						bottoms[h][n][n - othern] += (unique * p.second) % 9901;
					}
				}
			}
		}
	}
	cout << sols[K][N] << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// freopen("nocows.in", "r", stdin);
	// freopen("nocows.out", "w", stdout);
	solve();
	return 0;
}

