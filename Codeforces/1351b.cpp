#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	int x1 = a1 + a2, y1 = b1;
	int x2 = a1 + b2, y2 = b1;
	int x3 = b1 + a2, y3 = a1;
	int x4 = b1 + b2, y4 = a1;
	if ((x1 == y1 && b1 == b2) || (x2 == y2 && b1 == a2) || (x3 == y3 && a1 == b2) || (x4 == y4 && a1 == a2)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}