#include <bits/stdc++.h>

using namespace std;

void solve(int caseNum = 0) {
	int n;
	cin >> n;
	long long a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int L = 0, R = 0, good = 0;
	long long sum = a[0];
	while (L < n) {
		if (sum == 0) {
			sum -= a[L];
			L++;
			if (R > L) {
				long long tsum = sum;
				int tr = R;
				while (tr >= L && tsum - a[tr] != 0) {
					good++;
					tsum -= a[tr];
					tr--;
				}
			}
		} else {
			good++;
			if (R < n - 1) {
				R++;
				sum += a[R];
			} else {
				sum -= a[L];
				L++;
				if (R > L) {
					long long tsum = sum;
					int tr = R;
					while (tr >= L && tsum - a[tr] != 0) {
						good++;
						tsum -= a[tr];
						tr--;
					}
				}
			}
		}
		R = max(L, R);
	}
	cout << good;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef TESTING
	const string fileName = "";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
	#endif
	solve();
	return 0;
}