#include <bits/stdc++.h>
using namespace std;

void solve() {
	int x, y;
	string m;
	cin >> x >> y >> m;
	int t = 0;
	bool good = 0;
	for (char c : m) {
		t++;
		if (c == 'N') {
			y++;
		} else if (c == 'E') {
			x++;
		} else if (c == 'S') {
			y--;
		} else if (c == 'W') {
			x--;
		}
		if (abs(x) + abs(y) <= t) {
			cout << t << "\n";
			good = 1;
			break;
		}
	}
	if (!good) {
		cout << "IMPOSSIBLE\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}