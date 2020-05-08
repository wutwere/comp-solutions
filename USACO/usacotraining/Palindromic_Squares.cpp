/*
ID: blitesa1
LANG: C++14
PROG: palsquare
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
	int base;
	cin >> base;
	for (int i = 1; i <= 300; i++) {
		int sq = i * i;
		string sqToBase = convert(sq, base);
		if (isPalindrome(sqToBase)) {
			cout << convert(i, base) << " " << sqToBase << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef TESTING
	const string fileName = "palsquare";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
	#endif
	solve();
	return 0;
}