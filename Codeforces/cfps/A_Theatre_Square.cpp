#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	double n,m,a;
	cin >>n>>m>>a;
	long long h=ceil(n/a);
	long long v=ceil(m/a);
	cout << h*v;
	return 0;
}
