#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string word;
		cin >> word;
		if (word.length() > 10) {
			char f = word[0];
			char l = word[word.length()-1];
			int n = word.length()-2;
			cout << f << to_string(n) << l << endl;
		} else {
			cout << word << endl;
		}
	}
	return 0;
}
