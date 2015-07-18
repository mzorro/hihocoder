#include <iostream>
#include <vector>
#include <stack>
#pragma warning(disable:4996)
using namespace std;

int VN;
vector<bool> edges;

void dfs(int n, vector<int> &path) {
	int e[2] = { n << 1, (n << 1) + 1 };
	for (int i = 0; i < 2; i++) {
		if (edges[e[i]]) {
			edges[e[i]] = false;
			dfs(e[i] & ~VN, path);
		}
	}
	path.push_back(n);
}

int main() {
	// freopen("..\\input.txt", "r", stdin);
	int N;  cin >> N;
	if (N == 1) {
		cout << "01" << endl;
		return 0;
	}
	VN = 1 << (N - 1);
	edges = vector<bool>(VN<<1, true);

	vector<int> path;
	dfs(0, path);
	int len = path.size() - 1;
	while (len--) cout << (path[len] & 1);
	cout << endl;
}