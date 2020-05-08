#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	long long ways[10];
	ways[0] = 1;
	for (int j = 1; j <= n; j++) {
		ways[j % 10] = 0;
		for (int i = 0; i <= 6 && j - i >= 0; i++) {
			ways[j % 10] += ways[(j - i) % 10];
			ways[j % 10] %= (int) 1e9 + 7;
		}
	}
	cout << ways[n % 10] << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}