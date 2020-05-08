#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	for (int ii = 1; ii <= t; ii++) {
		cout << "Case #" << ii << ": ";
		string s;
		cin >> s;
		int slen = s.length();
		int nums[slen];
		for (int i = 0; i < slen; i++) {
			int n = s[i] - '0';
			//cout << n;
			nums[i] = n;
		}
		for (int i = slen - 1; i >= 0; i--) {
			int num = nums[i];
			int lnum, rnum;
			if (i == 0) lnum = 0; else lnum = nums[i-1];
			if (i == slen - 1) rnum = 0; else rnum = nums[i+1];
			if (num > rnum) {
				for (int j = 0; j < num-rnum; j++) s.insert(i+1,")");
			}
			if (num > lnum) {
				for (int j = 0; j < num-lnum; j++) s.insert(i,"(");
			}
		}
		cout << s << "\n";
	}
	return 0;
}
