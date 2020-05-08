/*
ID: blitesa1
LANG: C++14
PROG: sprime
*/
#include <bits/stdc++.h>

using namespace std;

vector<long long> primes = {2, 3, 5, 7};
vector<long long> res;
int n;

bool isPrime(long long n) {
	if (n == 1) return 0;
	for (long long p : primes) {
		if (p >= n) break;
		if (n % p == 0) {
			return 0;
		}
	}
	return 1;
}

void recurse(long long num = 0, int len = 0) {
	if (len == n) {
		res.push_back(num);
		return;
	}
	num *= 10;
	for (int i = 1; i <= 9; i++) {
		if (isPrime(num + i)) recurse(num + i, len + 1);
	}
}

void solve(int caseNum = 0) {
	cin >> n;
	for (long long i = 8; i < 1e4; i++) {
		if (isPrime(i)) primes.push_back(i);
	}
	recurse();
	sort(res.begin(), res.end());
	for (auto i : res) {
		cout << i << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef TESTING
	const string fileName = "sprime";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
	#endif
	solve();
	return 0;
}