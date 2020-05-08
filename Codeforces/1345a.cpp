#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	bool good = (n == 2 && m == 2) || (n == 1 || m == 1);
	cout << (good ? "YES" : "NO") << "\n";
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