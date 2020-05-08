/*
ID: blitesa1
LANG: C++14
PROG: crypt1
*/
#include <bits/stdc++.h>

using namespace std;

int n;
int nums[10];

bool isValid(int i) {
	while (i > 0) {
		int digit = i % 10;
		if (!binary_search(nums, nums + n, digit)) return 0;
		i -= digit;
		i /= 10;
	}
	return 1;
}

void solve(int caseNum = 0) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	fill(nums + n, nums + 10, 10);
	sort(nums, nums + n);
	int inds[5];
	int res = 0;
	fill(inds, inds + 5, 0);
	while (inds[4] < n) {
		int top = nums[inds[0]] * 100 + nums[inds[1]] * 10 + nums[inds[2]];
		int prod1 = top * nums[inds[4]];
		int prod2 = top * nums[inds[3]];
		if (prod1 < 1000 && prod2 < 1000 && prod1 + prod2 * 10 < 10000 && isValid(prod1) && isValid(prod2) && isValid(prod1 + prod2 * 10)) {
			// cout << top << " " << nums[inds[3]] << nums[inds[4]] << " "<< prod1 << " " << prod2 << " " << prod1 + prod2 * 10 << "\n";
			res++;
		}
		inds[0]++;
		for (int i = 1; i < 5; i++) {
			if (inds[i - 1] >= n) {
				inds[i - 1] = 0;
				inds[i]++;
			}
		}
	}
	cout << res << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef TESTING
	const string fileName = "crypt1";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
	#endif
	solve();
	return 0;
}