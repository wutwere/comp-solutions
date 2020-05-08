#include <bits/stdc++.h>

using namespace std;

void solve(int caseNum = 0) {
	double n;
	cin >> n;
	int res = ceil(n/2)-1;
	/*for (int i = 1; i < n; i++) {
		int b = n - i;
		if (i > b && b != 0) {
			res++;
		}
	}*/
	cout << res << "\n";
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
	int T;
	cin >> T;
	for (int caseNum = 1; caseNum <= T; caseNum++) {
		//cout << "Case #" << caseNum << ": ";
		solve(caseNum);
	}
	return 0;
}