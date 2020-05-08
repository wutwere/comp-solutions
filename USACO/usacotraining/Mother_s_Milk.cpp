/*
ID: blitesa1
LANG: C++14
PROG: milk3
*/
#include <bits/stdc++.h>

using namespace std;

int capacity[3];
int amount[3];
map<int, string> intToString;
unordered_set<string> already;
unordered_set<int> ralready;
vector<int> results;

string getKey() {
	return intToString[amount[0]] + "," + intToString[amount[1]] + "," + intToString[amount[2]];
}

void recurse(int bucket, int times) {
	//if (times >= 0) return;
	if (amount[0] == 0 && !ralready.count(amount[2])) {
		ralready.insert(amount[2]);
		results.push_back(amount[2]);
	}
	for (int i = 0; i < 3; i++) {
		if (amount[bucket] != 0 && i != bucket && amount[i] != capacity[i]) {
			int give = min(capacity[i] - amount[i], amount[bucket]);
			amount[i] += give;
			amount[bucket] -= give;
			string nkey = getKey();
			if (!already.count(nkey)) {
				already.insert(nkey);
				for (int j = 0; j < 3; j++) {
					recurse(j, times + 1);
				}
			}
			amount[i] -= give;
			amount[bucket] += give;
		}
	}
}

void solve(int caseNum = 0) {
	int highest = 0;
	for (int i = 0; i < 3; i++) {
		cin >> capacity[i];
		highest = max(capacity[i], highest);
		amount[i] = 0;
	}
	for (int i = 0; i <= highest; i++) {
		intToString[i] = to_string(i);
	}
	amount[2] = capacity[2];
	recurse(2, -capacity[2]);
	sort(results.begin(), results.end());
	for (int i = 0; i < results.size(); i++) {
		if (i) cout << " ";
		cout << results[i];
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef TESTING
	const string fileName = "milk3";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
	#endif
	solve();
	return 0;
}