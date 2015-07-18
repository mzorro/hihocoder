#include <iostream>
#include <vector>
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
	vector<bool> vsted(N + 1, false);
	vector<int> D(N + 1, MAX_INT);
	int cur = S, min = 0;
	D[S] = 0;
	while (cur != -1) {
		vsted[cur] = true;
		vector<pair<int, int> >::iterator it = G[cur].begin();
		for (; it != G[cur].end(); it++) {
			if (!vsted[it->first] && D[cur] + it->second < D[it->first]) {
				D[it->first] = D[cur] + it->second;
			}
		}
		cur = -1;
		int min = MAX_INT;
		for (int i = 1; i <= N; i++) {
			if (vsted[i]) continue;
			if (min > D[i]) {
				min = D[i];
				cur = i;
			}
		}
	}
	cout << D[T] << endl;
}