/*
ID: blitesa1
LANG: C++14
PROG: wormhole
*/
// LITERALLY STUCK ON THIS QUESTION FOR 5 HOURS AND HAD TO LOOK UP HELP BECAUSE I DIDNT KNOW HOW TO GENERATE ALL COMBINATIONS
#include <bits/stdc++.h>

using namespace std;

int n;
int poss = 0;
pair<int, int> coords[12];
map<int, int> pairings;

int findCoordToTheRight(int x, int y) {
	int lx = 1e9, li = -1;
	for (int i = 0; i < 12; i++) {
		if (coords[i].second == y && coords[i].first > x && coords[i].first < lx) {
			lx = coords[i].first;
			li = i;
		}
	}
	return li;
}

int getPair(int num) {
	if (pairings.count(num)) return pairings[num];
	return -1;
}

bool pairsAreGood() {
	bool good = 0;
	for (int k = 0; k < n; k++) {
		pair<int, int> c = coords[k];
		for (int l = 0; l < n; l++) {
			int rci = findCoordToTheRight(c.first, c.second);
			if (rci == -1) break;
			int newHole = getPair(rci);
			if (newHole == k) {
				good = 1;
				break;
			}
			c = coords[newHole];
		}
		if (good) break;
	}
	return good;
}

void recurse() {
	int i;
	for (i = 0; i < n; i++)
		if (!pairings.count(i)) break;
	
	if (i == n)
		poss += pairsAreGood();
	
	for (int j = 0; j < n; j++) {
		if (j != i && !pairings.count(j)) {
			pairings[i] = j;
			pairings[j] = i;
			recurse();
			pairings.erase(i);
			pairings.erase(j);
		}
	}
}

void solve(int caseNum = 0) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		coords[i] = {x, y};
	}
	recurse();
	cout << poss << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef TESTING
	const string fileName = "wormhole";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
	#endif
	solve();
	return 0;
}