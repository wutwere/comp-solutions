#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b, q;
	cin >> a >> b >> q;
	if (b > a) {
		swap(a, b);
	}
	int cnt[a * b + 1];
	cnt[0] = 0;
	for (int i = 1; i <= a * b; i++) {
		cnt[i] = cnt[i - 1] + (i % a % b != i % b % a);
	}
	for (int i = 0; i < q; i++) {
		long long l, r;
		cin >> l >> r;
		long long rc = ((r / (a * b)) * cnt[a * b] + cnt[r % (a * b)]);
		long long lc = ((l / (a * b)) * cnt[a * b] + cnt[l % (a * b)]);
		cout << rc - lc + (l % a % b != l % b % a) << " ";
	}
	cout << "\n";
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

