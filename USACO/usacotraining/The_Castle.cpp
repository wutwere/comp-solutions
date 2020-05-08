/*
ID: blitesa1
LANG: C++14
PROG: castle
*/
#include <bits/stdc++.h>

using namespace std;

int w, h;
int grid[50][50];
vector<array<int, 2>> pos;
map<int, int> graph[2500];
int comp[2500];

void floodFill(int node, int cur) {
	comp[node] = cur;
	if (pos[node][1] - 1 >= 0) {
		int upNode = grid[pos[node][0]][pos[node][1] - 1];
		if (comp[upNode] == -1) {
		if (graph[node][upNode]) {
			floodFill(upNode, cur);
		}
	}}
	if (pos[node][1] + 1 < h) {
		int downNode = grid[pos[node][0]][pos[node][1] + 1];
		if (comp[downNode] == -1) {
			if (graph[node][downNode]) {
				floodFill(downNode, cur);
			}
		}
	}
	if (pos[node][0] - 1 >= 0) {
		int leftNode = grid[pos[node][0] - 1][pos[node][1]];
		if (comp[leftNode] == -1) {
			if (graph[node][leftNode]) {
				floodFill(leftNode, cur);
			}
		}
	}
	if (pos[node][0] + 1 < w) {
		int rightNode = grid[pos[node][0] + 1][pos[node][1]];
		if (comp[rightNode] == -1) {
			if (graph[node][rightNode]) {
				floodFill(rightNode, cur);
			}
		}
	}
}

void solve(int caseNum = 0) {
	cin >> w >> h;
	for (int i = 0, ii = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			grid[i][j] = ii;
			pos.push_back({i, j});
			comp[ii] = -1;
			ii++;
		}
	}
	for (int j = 0; j < h; j++) {
		for (int i = 0; i < w; i++) {
			int n;
			cin >> n;
			if (j + 1 < h) graph[grid[i][j]][grid[i][j + 1]] = n < 8;
			if (i + 1 < w) graph[grid[i][j]][grid[i + 1][j]] = n % 8 < 4;
			if (j - 1 >= 0) graph[grid[i][j]][grid[i][j - 1]] = n % 4 < 2;
			if (i - 1 >= 0) graph[grid[i][j]][grid[i - 1][j]] = n % 2 < 1;
		}
	}
	int rooms = 0;
	int roomSizes[w * h];
	int biggest = 0;
	fill(roomSizes, roomSizes + w * h, 0);
	for (int j = 0; j < h; j++) {
		for (int i = 0; i < w; i++) {
			if (comp[grid[i][j]] == -1) {
				floodFill(grid[i][j], rooms);
				rooms++;
			}
			roomSizes[comp[grid[i][j]]]++;
			biggest = max(biggest, roomSizes[comp[grid[i][j]]]);
		}
	}
	cout << rooms << "\n" << biggest << "\n";
	string where = "1 1 N";
	for (int i = 0; i < w; i++) {
		for (int j = h - 1; j >= 0; j--) {
			int node = grid[i][j];
			if (pos[node][1] - 1 >= 0) {
				int upNode = grid[pos[node][0]][pos[node][1] - 1];
				if (comp[node] != comp[upNode]) {
					if (roomSizes[comp[node]] + roomSizes[comp[upNode]] > biggest) {
						biggest = roomSizes[comp[node]] + roomSizes[comp[upNode]];
						where = to_string(j + 1) + " " + to_string(i + 1) + " N";
					}
				}
			}
			if (pos[node][0] + 1 < w) {
				int rightNode = grid[pos[node][0] + 1][pos[node][1]];
				if (comp[node] != comp[rightNode]) {
					if (roomSizes[comp[node]] + roomSizes[comp[rightNode]] > biggest) {
						biggest = roomSizes[comp[node]] + roomSizes[comp[rightNode]];
						where = to_string(j + 1) + " " + to_string(i + 1) + " E";
					}
				}
			}
		}
	}
	cout << biggest << "\n" << where << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef TESTING
	const string fileName = "castle";
	if (fileName.length()) {
		freopen((fileName + ".in").c_str(), "r", stdin);
		freopen((fileName + ".out").c_str(), "w", stdout);
	}
	#endif
	solve();
	return 0;
}