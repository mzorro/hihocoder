#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#pragma warning(disable:4996)
#define MAX_BYTE 0x7f
#define MAX_INT 0x7fffffff

vector<set<int> > matrix;
vector<int> color, match;
bool dye(int n) {
	color[n] = 1;
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		set<int>::iterator it = matrix[t].begin();
		for (; it != matrix[t].end(); it++) {
			if (color[*it] == 0) {
				color[*it] = -color[t];
				q.push(*it);
			}
			else if (color[*it] == color[t]) {
				return false;
			}
		}
	}
	return true;
}

bool findPath(int u, vector<bool> &checked) {
	set<int>::iterator it = matrix[u].begin();
	for (; it != matrix[u].end(); it++) {
		if (checked[*it]) continue;
		checked[*it] = true;
		if (!match[*it] || findPath(match[*it], checked)) {
			match[u] = *it;
			match[*it] = u;
			return true;
		}
	}
	return false;
}

int main() {
	//freopen("..\\input.txt", "r", stdin);
	int N, M;
	cin >> N >> M;
	matrix = vector<set<int> >(N + 1);
	color = vector<int>(N + 1, 0);
	match = vector<int>(N + 1, 0);
	while (M--) {
		int u, v;
		cin >> u >> v;
		matrix[u].insert(v);
		matrix[v].insert(u);
	}
	for (int i = 1; i <= N; i++) {
		if (color[i] == 0 && !dye(i)) return 0;
	}
	for (int i = 1; i <= N; i++) {
		if (color[i] != 1 || match[i]) continue;
		vector<bool> checked(N + 1, false);
		findPath(i, checked);
	}
	int res = 0;
	for (int i = 1; i <= N; i++) res += match[i] == 0 ? 0 : 1;
	cout << res / 2 << endl;
	cout << N - res / 2 << endl;
}