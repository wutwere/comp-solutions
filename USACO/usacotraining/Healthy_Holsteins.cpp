/*
ID: blitesa1
LANG: C++14
PROG: holstein
*/
#include <bits/stdc++.h>

using namespace std;

int v, g, res;
int vreqs[25];
int feeds[15][26];
queue<vector<int>> states;

void bfs() {
	while (!states.empty()) {
		vector<int> s = states.front();
		states.pop();
		bool good = 1;
		for (int i = 0; i < v; i++) {
			if (s[i] < vreqs[i]) {
				good = 0;
				break;
			}
		}
		if (good) {
			vector<int> res;
			/*for (int i = 0; i < v + s[v] + 1; i++) {
				cerr << s[i] << " ";
			}*/
			for (int i = v + 1; i < v + s[v] + 1; i++) {
				res.push_back(s[i]);
			}
			//sort(res.begin(), res.end());
			cout << s[v] << " ";
			for (int i = 0; i < s[v]; i++) {
				if (i) cout << " ";
				cout << res[i] + 1;
			}
			cout << "\n";
			return;
		}
		for (int i = s[v + s[v]] + 1; i < g; i++) {
			vector<int> newState(v + s[v] + 1);
			for (int j = 0; j < v + s[v] + 1; j++) {
				newState[j] = s[j];
			}
			for (int j = 0; j < v; j++) {
				newState[j] += feeds[i][j];
			}
			newState.push_back(i);
			newState[v]++;
			states.push(newState);
		}
		s.clear();
	}
}

void solve(int caseNum = 0) {
	cin >> v;
	for (int i = 0; i < v; i++) {
		cin >> vreqs[i];
	}
	cin >> g;
	for (int i = 0; i < g; i++) {
		for (int j = 0; j < v; j++) {
			cin >> feeds[i][j];
		}
		feeds[i][v] = 1;
	}
	for (int i = 0; i < g; i++) {
		vector<int> newState(v + 2);
		for (int j = 0; j < v; j++) {
			newState[j] = feeds[i][j];
		}
		newState[v] = feeds[i][v];
		newState[v + 1] = i;
		states.push(newState);
	}
	bfs();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#else
	const string fileName = "holstein";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
#endif
	solve();
	return 0;
}