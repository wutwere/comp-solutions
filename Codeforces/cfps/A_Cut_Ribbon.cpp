#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,a,b,c;
	cin >> n >> a >> b >> c;
	int most=0;
	for (int i = 0; i<=n; i++) {
		for (int j = 0; j<=n;j++) {
			int k = (n-a*i-b*j)/c;
			if(k>=0&&a*i+b*j+c*k==n) {/*if(i+j+k>most)cout<<i<<","<<j<<","<<k<<"\n";*/most=max(most,i+j+k);}
		}
	}
	cout << most;
	return 0;
}
