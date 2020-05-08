#include <bits/stdc++.h>
using namespace std;

bool comp(array<int, 3> a, array<int, 3> b) {
	return a[1] < b[1];
}

void solve() {
	long long n, l, t, m = 0, wSum = 0, totW = 0;
	queue<long long> pf;
	map<int, int> meetings;
	cin >> n >> l;
	vector<array<int, 3>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i][0] >> v[i][1] >> v[i][2];
		totW += v[i][0];
	}
	sort(v.begin(), v.end(), comp);
	for (int i = n - 1, j = n - 1; i >= 0; i--) {
		if (v[i][2] == 1) {
			meetings[l - v[i][1]] += v[j][0];
			j--;
		}
	}
	for (int i = 0, j = 0; i < n; i++) {
		if (v[i][2] == -1) {
			meetings[v[i][1]] += v[j][0];
			j++;
		}
	}
	for (auto p : meetings) {
		wSum += p.second;
		if (wSum * 2 >= totW) {
			t = p.first;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (v[i][2] == -1) {
			while (pf.front() + 2 * t < v[i][1]) {
				pf.pop();
			}
			m += pf.size();
		} else {
			pf.push(v[i][1]);
		}
	}
	cout << m << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifndef LOCAL
		freopen("meetings.in", "r", stdin);
		freopen("meetings.out", "w", stdout);
	#endif
	solve();
	return 0;
}