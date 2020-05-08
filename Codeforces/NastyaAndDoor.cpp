#include <bits/stdc++.h>
using namespace std;

void solve(int caseNum = 0) {
	int n, k;
	cin >> n >> k;
	int hts[n];
	bool peaks[n];
	peaks[0] = 0;
	peaks[n - 1] = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		hts[i] = a;
		if (i > 1) {
			if (hts[i] < hts[i - 1] && hts[i - 1] > hts[i - 2]) {
				peaks[i - 1] = 1;
			} else {
				peaks[i - 1] = 0;
			}
		}
	}
	int l = 0, r = k - 1, cnt = 0, res = 0, bord = 0;
	for (int i = l + 1; i <= r - 1; i++) {
		if (peaks[i]) cnt++;
	}
	res = cnt;
	l++;
	r++;
	while (r < n) {
		// cout << l << " " << r << "\n";
		if (peaks[r - 1]) cnt++;
		if (peaks[l]) cnt--;
		if (cnt > res) {
			bord = l;
			res = cnt;
		}
		r++;
		l++;
	}
	cout << res + 1 << " " << bord + 1 << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef LOCAL
	const string fileName = "";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
#endif
	if (1) {
		int T;
		cin >> T;
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			//cout << "Case #" << caseNum << ": ";
			solve(caseNum);
		}
	} else solve();
	return 0;
}
