#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 2; i < n; i++) {
		if (n%i==0) {
			int other = floor(n/i);
			if (i*other==n){
				cout <<i << other;
				break;
			}
		}
	}
	return 0;
}
