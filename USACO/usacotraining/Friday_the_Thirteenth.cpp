/*
ID: blitesa1
LANG: C++11
PROG: friday
*/
#include <bits/stdc++.h>

using namespace std;

void solve(int case_num = 0) {
	int years;
	cin >> years;
	///int maxDays = years * 365;
	//for (int i = 1; i <= years; i++) {
	//	int y = 1900 + i;
	//	if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)) maxDays++;
	//}
	int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	map<int, int> count;
	int days = 0, wday = 2, month = 0, yr = 1900;//, totalDays = 0;
	while (yr < 1900 + years) {
		//totalDays++;
		if (days == 12) {
			//cout << month << " " << wday << "\n";
			count[wday]++;
		}
		days++;
		wday++;
		wday %= 7;
		bool leap = yr % 400 == 0 || (yr % 100 != 0 && yr % 4 == 0);
		if (days >= daysInMonth[month] + (month == 1 && leap)) {
			month++;
			days = 0;
		}
		if (month >= 12) {
			yr++;
			month = 0;
		}
	}
	for (int i = 0; i < 7; i++) {
		cout << count[i];
		if (i < 6) cout << " ";
	}
	cout << "\n";
}

int main() {
	const string usaco_file = "friday";
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	if (usaco_file.length()) {
		freopen((usaco_file + ".in").c_str(), "r", stdin);
		freopen((usaco_file + ".out").c_str(), "w", stdout);
	}
	solve();
	return 0;
}