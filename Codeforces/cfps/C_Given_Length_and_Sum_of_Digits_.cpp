#include <bits/stdc++.h>

using namespace std;

const bool print_case = 0;
const string usaco_file = "";

int get_sum_digits(long long i) {
	int sum = 0;
	while (i > 0) {
		int digit = i % 10;
		sum += digit;
		i -= digit;
		i /= 10;
	}
	return sum;
}

void solve(int case_num) {
	int m = case_num, s;
	cin >> s;
	if (s > 9*m || (m > 1 && s == 0)) {
		cout << "-1 -1";
		return;
	}
	int rem = s - 1;
	vector<int> nums;
	for (int i = 0; i < m - 1; i++) {
		int d = min(rem, 9);
		nums.push_back(d);
		rem -= d;
	}
	cout << rem + 1;
	for (int i = m - 2; i >= 0; i--) {
		cout << nums[i];
	}
	rem = s;
	cout << " ";
	for (int i = 0; i < m; i++) {
		int d = min(rem, 9);
		cout << d;
		rem -= d;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	if (usaco_file.length()) {
		freopen((usaco_file+".in").c_str(), "r", stdin);
		freopen((usaco_file+".out").c_str(), "w", stdout);
	}
	int T;
	cin >> T;
	solve(T);
	return 0;
}