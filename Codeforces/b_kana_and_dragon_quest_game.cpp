#include <bits/stdc++.h>

using namespace std;

void solve(int caseNum = 0) {
	int x, n, m;
	cin >> x >> n >> m;
	while (x > 20 && n--) {
		x /= 2;
		x += 10;
	}
	cout << (x > 10 * m ? "NO" : "YES") << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#else
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