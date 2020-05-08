#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	char la = s[s.length()-1];
	if (la=='0'||la=='2'||la=='4'||la=='6'||la=='8') cout << 0;
	else cout << 1;
	return 0;
}
