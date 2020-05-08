#include <bits/stdc++.h>

using namespace std;

void solve(int caseNum = 0) {
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << b << " " << c << " " << c << "\n";
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