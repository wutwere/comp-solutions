#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n,x;
		cin >> n >> x;
		set<int> nums;
		while (n--) {
			int a;
			cin >> a;
			nums.insert(a);
		}
		int last;
		for (int i = 1; x>0; i++) {
			if (nums.count(i) == 0) {
				nums.insert(i);
				x--;
			}
			last = i;
		}
		for (int i = last; nums.count(i); i++) last = i;
		cout << last << "\n";
	}
	return 0;
}
