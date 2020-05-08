#include <bits/stdc++.h>
using namespace std;

int edge = 1e9;
int T, a, b;
vector<pair<int, int>> pts = {
	{0, 0}, {edge / 2, edge / 2}, {-edge / 2, edge / 2}, {-edge / 2, -edge / 2}, {edge / 2, -edge / 2}
};

string query(long long x, long long y) {
	cout << x << " " << y << "\n";
	// cerr << x << " " << y << "\n";
	cout.flush();
	string resp;
	cin >> resp;
	if (resp == "WRONG")
		exit(0);
	return resp;
}

void solve(int caseNum = 0) {
	long long ix, iy;
	for (auto p : pts) {
		string s = query(p.first, p.second);
		if (s == "CENTER") return;
		else if (s == "HIT") {
			ix = p.first;
			iy = p.second;
			break;
		}
	}
	long long px1, py1 = iy;
	long long lx = -edge, ux = ix;
	for (int i = 0; i < 30; i++) {
		long long mx = (lx + ux) / 2;
		string s = query(mx, py1);
		if (s == "MISS") {
			lx = mx;
		} else if (s == "HIT") {
			ux = mx;
		} else if (s == "CENTER") {
			return;
		}
	}
	px1 = ux;
	long long px2, py2 = iy;
	lx = ix, ux = edge;
	for (int i = 0; i < 30; i++) {
		long long mx = (lx + ux) / 2;
		string s = query(mx, py2);
		if (s == "HIT") {
			lx = mx;
		} else if (s == "MISS") {
			ux = mx;
		} else if (s == "CENTER") {
			return;
		}
	}
	px2 = lx;
	long long px3 = px2, py3;
	lx = -edge, ux = iy;
	for (int i = 0; i < 30; i++) {
		long long mx = (lx + ux) / 2;
		string s = query(px3, mx);
		if (s == "MISS") {
			lx = mx;
		} else if (s == "HIT") {
			ux = mx;
		} else if (s == "CENTER") {
			return;
		}
	}
	py3 = ux;
	long long px4 = px3, py4;
	lx = iy, ux = edge;
	for (int i = 0; i < 30; i++) {
		long long mx = (lx + ux) / 2;
		string s = query(px4, mx);
		if (s == "HIT") {
			lx = mx;
		} else if (s == "MISS") {
			ux = mx;
		} else if (s == "CENTER") {
			return;
		}
	}
	py4 = lx;
	query((px1 + px2) / 2, (py3 + py4) / 2);
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
		cin >> T >> a >> b;;
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			// cout << "Case #" << caseNum << ": ";
			solve(caseNum);
		}
	} else solve();
	return 0;
}