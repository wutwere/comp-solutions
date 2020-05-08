/*
ID: blitesa1
LANG: C++11
PROG: transform
*/
#include <bits/stdc++.h>

using namespace std;

int n;
map<int, map<int, char>> sq1;
map<int, map<int, char>> sq2;

bool is90Deg() {
	for (int x = 0; x < n; x++) for (int y = 0; y < n; y++) if (sq1[x][y] != sq2[y][-x + n - 1]) return 0; //(y, -x)
	return 1;
}

bool is180Deg() {
	for (int x = 0; x < n; x++) for (int y = 0; y < n; y++) if (sq1[x][y] != sq2[-x + n - 1][-y + n - 1]) return 0; //(-x, -y)
	return 1;
}

bool is270Deg() {
	for (int x = 0; x < n; x++) for (int y = 0; y < n; y++) if (sq1[x][y] != sq2[-y + n - 1][x]) return 0; //(-y, x)
	return 1;
}

void reflect() {
	map<int, map<int, char>> newsq1;
	for (int x = 0; x < n; x++) for (int y = 0; y < n; y++) newsq1[x][y] = sq1[-x + n - 1][y]; //(-x, y)
	sq1 = newsq1;
}

void solve(int case_num = 0) {
	cin >> n;
	for (int y = n - 1; y >= 0; y--)
		for (int x = 0; x < n; x++)
			cin >> sq1[x][y];
	for (int y = n - 1; y >= 0; y--)
		for (int x = 0; x < n; x++)
			cin >> sq2[x][y];
	bool isSame = sq1 == sq2;
	if (is90Deg()) cout << "1\n";
	else if (is180Deg()) cout << "2\n";
	else if (is270Deg()) cout << "3\n";
	else {
		reflect();
		if (sq1 == sq2) cout << "4\n";
		else if (is90Deg()) cout << "5\n";
		else if (is180Deg()) cout << "5\n";
		else if (is270Deg()) cout << "5\n";
		else if (isSame) cout << "6\n";
		else cout << "7\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef TESTING
	const string usaco_file = "transform";
	if (usaco_file.length()) {
		freopen((usaco_file + ".in").c_str(), "r", stdin);
		freopen((usaco_file + ".out").c_str(), "w", stdout);
	}
	#endif
	solve();
	return 0;
}