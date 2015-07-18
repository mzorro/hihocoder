#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)
#define MAX_BYTE 0x7f
#define MAX_INT 0x7fffffff
#define REP(nn, bb, ee) for (int nn = bb; nn <= N; nn++)

int main() {
	//freopen("..\\input.txt", "r", stdin);
	int N, M;
	cin >> N >> M;
	vector<vector<int> > matrix(N + 1, vector<int>(N + 1, MAX_INT>>1));
	REP(i, 1, N) matrix[i][i] = 0;
	while (M--) {
		int from, to, value;
		cin >> from >> to >> value;
		matrix[from][to] = matrix[from][to] < value ? matrix[from][to] : value;
		matrix[to][from] = matrix[to][from] < value ? matrix[to][from] : value;
	}
	REP(w, 1, N) REP(i, 1, N) REP(j, 1, N)
		if (matrix[i][j] > matrix[i][w] + matrix[w][j])
			matrix[i][j] = matrix[i][w] + matrix[w][j];

	REP(i, 1, N) {
		cout << matrix[i][1];
		REP(j, 2, N) cout << ' ' << matrix[i][j];
		cout << endl;
	}
}