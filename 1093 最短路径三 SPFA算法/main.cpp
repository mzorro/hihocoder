#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#pragma warning(disable:4996)
#define MAX_BYTE 0x7f
#define MAX_INT 0x7fffffff

int main() {
	//freopen("..\\input.txt", "r", stdin);
	int N, M, S, T;
	cin >> N >> M >> S >> T;
	vector<vector<pair<int, int> > > G(N + 1, vector<pair<int, int> >());
	while (M--) {
		int from, to, value;
		cin >> from >> to >> value;
		G[from].push_back(pair<int, int>(to, value));
		G[to].push_back(pair<int, int>(from, value));
	}

	queue<int> q;
	vector<int> dist(N + 1, MAX_INT);
	vector<bool> inq(N + 1, false);
	q.push(S);
	dist[S] = 0;
	inq[S] = true;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		inq[t] = false;
		vector<pair<int, int> >::iterator it = G[t].begin();
		for (; it != G[t].end(); it++) {
			if (dist[it->first] > dist[t] + it->second) {
				dist[it->first] = dist[t] + it->second;
				if (!inq[it->first]) q.push(it->first);
			}
		}
	}
	cout << dist[T] << endl;
}