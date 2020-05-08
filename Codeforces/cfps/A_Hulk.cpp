#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	string s = "I hate";
	int nn = n;
	while (--nn) {
		s += " that I ";
		s += (nn-n)%2==0?"hate":"love";
	}
	s += " it";
	cout << s;
	return 0;
}
