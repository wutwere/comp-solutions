#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	int total=0;
	while (t--) {
		int a,b,c;
		cin >> a >> b>>c;
		if (a+b+c>=2){
			total++;
		}
	}
	cout << total;
	return 0;
}
