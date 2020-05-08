#include <bits/stdc++.h>

using namespace std;

bool isPerm(set<int> perm) {
	if (perm.size() == 0) return 0;
	for (int i = 0; i < perm.size(); i++) {
		if (!perm.count(i+1)) return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; 
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> nums;
		while (n--) {
			int a;
			cin >> a;
			nums.push_back(a);
		}
		set<int> firstP;
		for (int a : nums) {
			if (firstP.count(a) == 0) {
				firstP.insert(a);
			} else {
				break;
			}
		}
		set<int> secondP;
		for (int i = firstP.size(); i < nums.size(); i++) {
			if (secondP.count(nums[i]) == 0) secondP.insert(nums[i]);
			else break;
		}
		int s1 = firstP.size();
		int s2 = secondP.size();
		bool poss = isPerm(firstP) && isPerm(secondP) && s1 + s2 == nums.size();
		firstP.clear();
		secondP.clear();
		for (int i = nums.size()-1; i >= 0; i--) {
			int a = nums[i];
			if (firstP.count(a) == 0) {
				firstP.insert(a);
			} else {
				break;
			}
		}
		for (int i = 0; i < nums.size() - firstP.size(); i++) {
			if (secondP.count(nums[i]) == 0) secondP.insert(nums[i]);
			else {
				break;
			}
		}
		bool sposs = isPerm(firstP) && isPerm(secondP) && firstP.size() + secondP.size() == nums.size() && !(firstP.size() == s2 && secondP.size() == s1);
		cout << poss + sposs << "\n";
		if (sposs) cout << secondP.size() << " " << firstP.size() << "\n";
		if (poss) cout << s1 << " " << s2 << "\n";
	}
	return 0;
}
