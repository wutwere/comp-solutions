#include <bits/stdc++.h>
using namespace std;

int n, m, cc = 0;
string s;
vector<vector<int>> edge(100000);
vector<int> comp(100000);

void dfs(int cur, int parent = 0) {
	if (parent && s[cur - 1] == s[parent - 1]) {
		comp[cur - 1] = comp[parent - 1];
	} else {
		cc++;
		comp[cur - 1] = cc;
	}
	for (int nb : edge[cur]) {
		if (nb != parent) {
			dfs(nb, cur);
		}
	}
}

void solve() {
	cin >> n >> m >> s;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs(1);
	for (int i = 0; i < m; i++) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		cout << (comp[a - 1] != comp[b - 1] || s[a - 1] == c);
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifndef LOCAL
		freopen("milkvisits.in", "r", stdin);
		freopen("milkvisits.out", "w", stdout);
	#endif
	solve();
	return 0;
}