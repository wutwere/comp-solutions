/*
ID: blitesa1
LANG: C++14
PROG: hamming
*/
#include <bits/stdc++.h>

using namespace std;

int countOnes(int num, int b) {
	int res = 0;
	while (b--) {
		// cerr << b << "\n";
		int p = pow(2, b);
		if (num >= p) {
			res++;
			num %= p;
		}
	}
	return res;
}

void solve(int caseNum = 0) {
	int N, B, D;
	cin >> N >> B >> D;
	vector<int> res;
	int ressize = 0;
	for (int i = 0; ressize < N && i < 1e7; i++) {
		bool good = 1;
		for (int num : res) {
			// cerr << i << " " << num << " " << (i ^ num) << "\n";
			if (countOnes(i ^ num, B) < D) {
				good = 0;
				break;
			}
		}
		if (good) {
			res.push_back(i);
			ressize++;
		}
	}
	for (int i = 0; i < ressize; i++) {
		if (i) if (i % 10 == 0) cout << "\n";
		else cout << " ";
		cout << res[i];
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#else
	const string fileName = "hamming";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
#endif
	if (0) {
		int T;
		cin >> T;
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			//cout << "Case #" << caseNum << ": ";
			solve(caseNum);
		}
	} else solve();
	return 0;
}