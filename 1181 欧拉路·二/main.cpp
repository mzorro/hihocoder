#include <iostream>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

int N;
vector<vector<int> > matrix;

void dfs(int n) {
	for (int i = 0; i < N; i++) {
		if (matrix[n][i]) {
			matrix[n][i]--;
			matrix[i][n]--;
			dfs(i);
		}
	}
	cout << n+1 << ' ';
}

int main() {
	// freopen("..\\input.txt", "r", stdin);
	int M;
	cin >> N >> M;
	matrix = vector<vector<int> >(N, vector<int>(N, 0));
	vector<int> du(N, 0);
	int oddV = 0;
	while (M--) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		matrix[u][v]++;
		matrix[v][u]++;
		if (++du[u] % 2 == 1) oddV = u;
		if (++du[v] % 2 == 1) oddV = v;
	}
	dfs(oddV);
	cout << endl;
}