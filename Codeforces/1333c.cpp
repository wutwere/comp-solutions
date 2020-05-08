#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> sums;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		if (a != 0) {
			for (long long &s : sums) {
				if (s != 0) {
					s += a;
					ans += s != 0;
				}
			}
			ans++;
			sums.push_back(a);
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

