#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int fo=0;
	int fe=0;
	int ne=0;
	int no=0;
	for (int i=1;i<=n;i++) {
		int a;
		cin >> a;
		if (a%2==1) {no++; if(!fo) fo=i;}
		if (a%2==0) {ne++; if(!fe) fe=i;}
	}
	if (ne>no) cout << fo;
	else cout << fe;
	return 0;
}
