#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> steps(n + 1);
	steps[0] = 0;
	for (int i = 1; i <= n; i++) {
		steps[i] = 1e9;
		int x = i;
		while (x) {
			int d = x % 10;
			steps[i] = min(steps[i], steps[i - d] + 1);
			(x -= d) /= 10;
		}
	}
	cout << steps[n] << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}