#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	cin >> n;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	while (n--) {
		long long a;
		cin >> a;
		long long rt = sqrt(a);
		if (rt * rt != a || a == 1) {
			cout << "NO\n";
			continue;
		}
		bool tprime = 1;
		for (int i = 2; i <= sqrt(rt); i++) {
			if (rt % i == 0) {
				tprime = 0;
				break;
			}
		}
		if (tprime) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
