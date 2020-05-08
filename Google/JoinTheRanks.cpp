#include <bits/stdc++.h>
using namespace std;

void solve(int caseNum = 0) {
	int r, s;
	cin >> r >> s;
	vector<int> v(r * s);
	int moves = 0;
	vector<pair<int, int>> rv;
	for (int j = 0, ind = 0; j < s; j++) {
		for (int i = 0; i < r; i++) {
			v[ind] = i + 1;
			ind++;
		}
	}
	auto isSorted = [&]() {
		for (int i = 1; i < r * s; i++) {
			if (v[i] < v[i - 1])
				return 0;
		}
		return 1;
	};
	while (!isSorted()) {
		int ub, under;
		for (ub = r * s - 2; ub >= 0; ub--) {
			if (v[ub] == v[0]) {
				under = v[ub + 1];
				break;
			}
		}
		if (ub == 0) {
			ub = r * s - 1;
			under = v[ub];
		}
		int lb;
		for (lb = 0; lb < r * s; lb++) {
			if (v[lb] == under) {
				while (v[lb + 1] == under) {
					lb++;
				}
				break;
			}
		}
		rv.push_back({lb + 1, ub - lb});
		moves++;
		vector<int> cool(v.begin() + lb + 1, v.begin() + ub + 1);
		v.erase(v.begin() + lb + 1, v.begin() + ub + 1);
		v.insert(v.begin(), cool.begin(), cool.end());
	}
	cout << moves << "\n";
	for (auto p : rv) {
		cout << p.first << " " << p.second << "\n";
	}
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

