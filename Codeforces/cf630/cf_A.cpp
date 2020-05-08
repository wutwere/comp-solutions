#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		int x,y,x1,y1,x2,y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		int hd=x+b-a;
		int yd=y+d-c;
		bool br = true;
		if(a+b>0) br=abs(x1-x)>=1||abs(x2-x)>=1;
		if(c+d>0) br=br&&(abs(y1-y)>=1||abs(y2-y)>=1);
		if(hd>=x1&&hd<=x2&&yd>=y1&&yd<=y2&&br) cout << "YES"<<endl;
		else cout << "NO"<<endl;

	}
	return 0;
}
