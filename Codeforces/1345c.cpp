#include <bits/stdc++.h>
using namespace std;

int mod(int a, int b) {
	return (a % b + b) % b;
}

void solve() {
	int n;
	bool good = 1;
	unordered_set<int> rooms;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		int k = -a[i];
		int r = k + a[mod(k, n)];
		if (rooms.count(r)) {
			good = 0;
		}
		rooms.insert(r);
	}
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