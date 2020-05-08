#include <bits/stdc++.h>
using namespace std;

bool isOdd(int num) {
	return num & 1 == 1;
}

void solve(int caseNum = 0) {
	int x, y;
	cin >> x >> y;
	string s = "";
	while (1) {
		if (isOdd(x + y)) {
			if (y - 1 == 0 && x == 0) {
				y--;
				s += "N";
			} else if (x - 1 == 0 && y == 0) {
				x--;
				s += "E";
			} else if (y + 1 == 0 && x == 0) {
				y++;
				s += "S";
			} else if (x + 1 == 0 && y == 0) {
				x++;
				s += "W";
			} else if (isOdd(y) && isOdd((y - 1 + x) / 2)) {
				y--;
				s += "N";
			} else if (isOdd(x) && isOdd((x - 1 + y) / 2)) {
				x--;
				s += "E";
			} else if (isOdd(y) && isOdd((y + 1 + x) / 2)) {
				y++;
				s += "S";
			} else if (isOdd(x) && isOdd((x + 1 + y) / 2)) {
				x++;
				s += "W";
			} else {
				s = "IMPOSSIBLE";
				break;
			}
			x /= 2;
			y /= 2;
		} else if (x == 0 && y == 0) {
			break;
		} else {
			s = "IMPOSSIBLE";
			break;
		}
	}
	cout << s << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef LOCAL
	const string fileName = "";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
#endif
	if (1) {
		int T;
		cin >> T;
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			cout << "Case #" << caseNum << ": ";
			solve(caseNum);
		}
	} else solve();
	return 0;
}