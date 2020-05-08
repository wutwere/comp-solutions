#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int input;
	cin >> input;
	long long n = floor(input/1000);
	long long m = input%1000;
	for (long long i = n-2; i > 0; i-=2) {
		n *= i;
	}
	//cout << n << endl;
	n %= m;
	cout <<n;
	return 0;
}
