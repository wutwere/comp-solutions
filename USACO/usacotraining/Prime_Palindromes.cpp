/*
ID: blitesa1
LANG: C++14
PROG: pprime
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> primes = {2, 3, 5, 7};

bool isPrime(int n) {
	for (int p : primes) {
		if (p >= n) break;
		if (n % p == 0) {
			return 0;
		}
	}
	return 1;
}

void solve(int caseNum = 0) {
	int a, b;
	cin >> a >> b;
	// generate primes from 2 to 1e4
	for (int i = 8; i < 1e4; i++) {
		if (isPrime(i)) primes.push_back(i);
	}
	// generate palindromes
	vector<int> res;
	for (int len = 1; len <= 6; len++) {
		int digits[len];
		fill(digits, digits + len, 0);
		digits[0]++;
		while (1) {
			long long onum = 0;
			for (int i = 0; i < len; i++) {
				onum *= 10;
				onum += digits[i];
			}
			for (int j = 1; j <= 2; j++) {
				long long num = onum;
				for (int i = len - j; i >= 0; i--) {
					num *= 10;
					num += digits[i];
				}
				if (num >= a && num <= b && isPrime(num)) {
					res.push_back(num);
				}
			}
			digits[0]++;
			for (int i = 1; i < len; i++) {
				if (digits[i - 1] > 9) {
					digits[i - 1] = 0;
					digits[i]++;
				}
			}
			if (digits[0] == 0) digits[0]++;
			if (digits[len - 1] > 9) break;
		}
	}
	sort(res.begin(), res.end());
	for (int i : res) {
		cout << i << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef TESTING
	const string fileName = "pprime";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
	#endif
	solve();
	return 0;
}