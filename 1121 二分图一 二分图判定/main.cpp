#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#pragma warning(disable:4996)
#define MAX_BYTE 0x7f
#define MAX_INT 0x7fffffff

vector<set<int> > matrix;
vector<int> color;

bool bfs(int n) {
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

int main() {
	//freopen("..\\input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		matrix = vector<set<int> >(N + 1);
		while (M--) {
			int u, v;
			cin >> u >> v;
			matrix[u].insert(v);
			matrix[v].insert(u);
		}
		color = vector<int>(N + 1, 0);
		bool correct = true;
		for (int i = 1; correct && i <= N; i++) {
			if (color[i] == 0 && !bfs(i)) correct = false;
		}
		if (correct) cout << "Correct" << endl;
		else cout << "Wrong" << endl;
	}
}