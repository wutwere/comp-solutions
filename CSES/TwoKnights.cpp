#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int bad = 0;
		if (i >= 5) bad = 8;
		else if (i >= 4) bad = 4;
		else if (i >= 3) bad = 2;
		int x = i * i;
		cout << (x - bad) * (x - 1) / 2 << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}