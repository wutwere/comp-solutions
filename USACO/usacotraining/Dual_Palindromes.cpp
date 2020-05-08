/*
ID: blitesa1
LANG: C++14
PROG: dualpal
*/
#include <bits/stdc++.h>

using namespace std;

char getDigit(int num) {
	return num >= 0 && num <= 9 ? num + '0' : num - 10 + 'A';
}

string convert(int num, int base) {
	string res = "";
	while (num > 0) {
		res = getDigit(num % base) + res;
		num /= base;
	}
	return res;
}

bool isPalindrome(string s) {
	int len = s.length();
	for (int i = 0; i < len/2; i++)
		if (s[i] != s[len - 1 - i]) return 0;
	return 1;
}

void solve(int caseNum = 0) {
	int n, s;
	cin >> n >> s;
	int found = 0;
	while (found < n) {
		s++;
		int pals = 0;
		for (int i = 2; i <= 10; i++) {
			if (isPalindrome(convert(s, i))) {
				pals++;
			}
		}
		if (pals >= 2) {
			found++;
			cout << s << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef TESTING
	const string fileName = "dualpal";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
	#endif
	solve();
	return 0;
}