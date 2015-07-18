#include <iostream>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

int N;
vector<vector<int> > matrix;
bool isConnected() {
	vector<bool> vst(N, false);
	queue<int> q;
	q.push(0);
	vst[0] = true;
	int vcnt = 0;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		vcnt++;
		vector<int>::iterator it = matrix[t].begin();
		for (; it != matrix[t].end(); it++) {
			if (vst[*it]) continue;
			vst[*it] = true;
			q.push(*it);
		}
	}
	if (vcnt == N) return true;
	return false;
}

int main() {
	// freopen("..\\input.txt", "r", stdin);
	int M;
	cin >> N >> M;
	matrix = vector<vector<int> >(N);
	vector<int> du(N, 0);
	int odd = 0;
	while (M--) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		matrix[u].push_back(v);
		matrix[v].push_back(u);
		odd += ((++du[u]) % 2 == 0) ? -1 : 1;
		odd += ((++du[v]) % 2 == 0) ? -1 : 1;
	}
	if ((odd == 0 || odd == 2) && isConnected())
		cout << "Full" << endl;
	else
		cout << "Part" << endl;
}