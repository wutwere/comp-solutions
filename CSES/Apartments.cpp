#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m, k, ans = 0;
	cin >> n >> m >> k;
	int a[n], b[m];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + m);
	for (int i = 0, j = 0; i < n && j < m; i++) {
		while (b[j] < a[i] - k)
			j++;
		if (j >= m)
			break;
		if (b[j] <= a[i] + k) {
			ans++;
			j++;
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}