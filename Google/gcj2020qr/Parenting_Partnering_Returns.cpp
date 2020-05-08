#include <bits/stdc++.h>

using namespace std;

bool overlaps(vector<pair<int, int>> sched, int s, int e) {
	for (pair<int, int> i : sched) {
		if (max(i.first, s) - min(i.second, e) < 0) return 1;
	}
	return 0;
}

string search(vector<pair<int, int>> items, string y = "", vector<pair<int, int>> cs = {}, vector<pair<int, int>> js = {}) {
	if (y.length() == items.size() || y == "IMPOSSIBLE") return y;
	int len = y.length();
	pair<int, int> i = items[len];
	string s1 = "IMPOSSIBLE", s2 = "IMPOSSIBLE";
	if (!overlaps(cs, i.first, i.second)) {
		cs.push_back(i);
		s1 = search(items, y + "C", cs, js);
		cs.pop_back();
	}
	if (!overlaps(js, i.first, i.second)) {
		js.push_back(i);
		s2 = search(items, y + "J", cs, js);
		js.pop_back();
	}
	if (s1 != "IMPOSSIBLE") return s1;
	if (s2 != "IMPOSSIBLE") return s2;
	return "IMPOSSIBLE";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	for (int ii = 1; ii <= t; ii++) {
		cout << "Case #" << ii << ": ";
		int n;
		cin >> n;
		string y = "";
		vector<pair<int, int>> cs;
		vector<pair<int, int>> js;
		vector<pair<int, int>> items;
		bool imp = 0;
		while (n--) {
			int s, e;
			cin >> s >> e;
			items.push_back({s, e});
		}
		cs.push_back(items[0]);
		y = search(items, "C", cs);
		cout << y << "\n";
		/*for (int i = items.size() - 1; i >= 0; i--) {
			int s = items[i].first;
			int e = items[i].second;
			if (imp) continue;
			if (!overlaps(cs, s, e)) {y = "C" + y; cs.push_back(items[i]);}
			else if (!overlaps(js, s, e)) {y = "J" + y; js.push_back(items[i]);}
			else imp = 1;
		}
		if (!imp) cout << y << "\n";
		else cout << "IMPOSSIBLE\n";*/
	}
	return 0;
}
