/*
ID: blitesa1
LANG: C++14
PROG: sort3
*/
#include <bits/stdc++.h>

using namespace std;

void solve(int caseNum = 0) {
	int n;
	cin >> n;
	int nums[n];
	int count[4];
	fill(count, count + 4, 0);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		count[nums[i]]++;
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (nums[i] == 1 && i >= count[1]) {
			int find;
			bool swapped = 0;
			if (i >= count[1] + count[2]) find = 3;
			else find = 2;
			for (int j = 0; j < count[1]; j++) {
				if (nums[j] == find) {
					swapped = 1;
					nums[j] = 1;
					nums[i] = find;
					break;
				}
			}
			if (!swapped) {
				find = 2;
				for (int j = 0; j < count[1]; j++) {
					if (nums[j] == find) {
						nums[j] = 1;
						nums[i] = find;
						break;
					}
				}
			}
			res++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (nums[i] == 2 && i >= count[1] + count[2]) {
			int find = 3;
			for (int j = count[1]; j < count[1] + count[2]; j++) {
				if (nums[j] == find) {
					nums[j] = 2;
					nums[i] = find;
					break;
				}
			}
			res++;
		}
	}
	cout << res << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef TESTING
	const string fileName = "sort3";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
	#endif
	solve();
	return 0;
}