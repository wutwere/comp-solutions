#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int nums;
		cin >> nums;
		map<int,int> used;
		map<int,int> u2;
		vector<int> o;
		while (nums--) {
			int n;
			cin >> n;
			o.push_back(n);
		}
		int m=1;
		while (m<=11) {
			int gg,gc=0;
			vector<pair<int,int>> gtn;
			for (int i=2;i<1000;i++){
				int ng = 0;
				for (int n : o) {
					if (i!=n&&n%i==0) {
						ng++;
						gtn.push_back(make_pair(i,n));
					}
				}
				if(ng>gg){
					gg=ng;
					gc=i;
				}
				if(ng==nums) break;
			}
			for(auto it : gtn) {
				int a=it.first;
				int b=it.second;
				if (a==gc&&used.count(b)==0) {
					used[b]=m;
					u2[m]++;
				}
			}
			m++;
		}
		int c=0;
		for (auto v:u2) c++;
		cout << c << endl;
		for (int i : o) {
			cout << used[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
