#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int num;
	cin >> num;
	bool asd = false;
	vector<int> p{0, 4, 7};
	for (int i : p) {
		for (int j : p) {
			for (int k : p) {
				for (int l = 4; l < 8; l+=3) {
					int d = i*1000+j*100+k*10+l;
					float q = (float)num/d;
					if (abs(floor(q)-q)<0.00001) {
						asd = true;
						break;
					}
				}
			}
		}
	}
	string r = asd?"YES":"NO";
	cout << r;
	return 0;
}
