#include <bits/stdc++.h>

using namespace std;

std::string toBinary(int n)
{
    std::string r;
	int i = 6;
    while(i--) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	string b = toBinary(n);
	char a = b[1];
	b[1] = b[5];
	b[5] = a;
	char ss = b[2];
	b[2] = b[3];
	b[3] = ss;
	cout << stoi(b,0,2);
	cout << bitset<8>(n).to_string();
	return 0;
}
