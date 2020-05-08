#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	unordered_map<int, unordered_map<int, int>> id;
	unordered_map<int, unordered_map<int, bool>> grid;
	int x = 0, y = 0, curId = 0;
	auto getId = [&](int a, int b) {
		if (id.count(a) && id[a].count(b)) return id[a][b];
		curId++;
		id[a][b] = curId;
		return curId;
	};
	int t = 0;
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		int oldId = getId(x, y);
		if (c == 'N') y++;
		else if (c == 'S') y--;
		else if (c == 'E') x++;
		else if (c == 'W') x--;
		else continue;
		int newId = getId(x, y);
		if (grid.count(oldId) && grid[oldId].count(newId)) {
			t += 1;
		} else {
			t += 5;
		}
		grid[oldId][newId] = 1;
		grid[newId][oldId] = 1;
	}
	cout << t << "\n";
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