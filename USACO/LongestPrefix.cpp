/*
ID: blitesa1
LANG: C++14
PROG: prefix
*/

#include <bits/stdc++.h>
using namespace std;

int n, fseqlen = 0, seqlen = 0, longest = 0, cool = 0;
string prim[200];
int lens[200];
bool usedlens[200011];
string seq;

bool match(int cur, int l, string p) {
	for (int i = 0; i < l; i++) {
		if (p[i] != seq[cur + i - cool]) {
			return 0;
		}
	}
	return 1;
}

void dfs(int cur) {
	for (int i = 0; i < n; i++) {
		if (cur + lens[i] <= seqlen && !usedlens[cur + lens[i]]) {
			if (match(cur, lens[i], prim[i])) {
				usedlens[cur + lens[i]] = 1;
				longest = max(longest, cur + lens[i]);
				dfs(cur + lens[i]);
			}
		}
	}
}

void solve() {
	for (n = 0; ; n++) {
		string p;
		cin >> p;
		if (p == ".") {
			break;
		}
		prim[n] = p;
		lens[n] = p.length();
	}
	while (1) {
		string s;
		cin >> s;
		if (s.length() && s != "\n" && s != ".") {
			seq += s;
			seqlen += s.length();
			fseqlen += s.length();
			if (fseqlen > 30000) {
				dfs(longest);
				seq = seq.substr(longest - cool, seq.length() - longest - cool);
				fseqlen -= longest - cool;
				cool = longest;
			}
		} else {
			break;
		}
	}
	memset(usedlens, 0, sizeof(usedlens));
	dfs(longest);
	cout << longest << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// freopen("prefix.in", "r", stdin);
	// freopen("prefix.out", "w", stdout);
	solve();
	return 0;
}

