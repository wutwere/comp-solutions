#include <bits/stdc++.h>

using namespace std;

void solve(int caseNum = 0) {
	int n, wealth;
	cin >> n >> wealth;
	long long people[n];
	for (int i = 0; i < n; i++) {
		cin >> people[i];
	}
	sort(people, people + n);
	long long sum = 0, count = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (sum + people[i] < wealth * (count + 1)) {
			cout << count << "\n";
			return;
		} else {
			sum += people[i];
			count++;
		}
	}
	cout << count << "\n";
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