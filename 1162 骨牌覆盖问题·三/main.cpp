#include <iostream>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define MOD 12357
typedef long long ll;

struct Matrix {
	int m, n;
	vector<vector<ll> > a;

	Matrix(int m, int n) : m(m), n(n) {
		a = vector<vector<ll> >(m, vector<ll>(n));
	}

	void operator*=(const Matrix &r) {
		Matrix res(m, r.n);
		for (int row = 0; row < m; row++) {
			for (int col = 0; col < r.n; col++) {
				for (int k = 0; k < n; k++) {
					res.a[row][col] += a[row][k] * r.a[k][col];
					res.a[row][col] %= MOD;
				}
			}
		}
		*this = res;
	}
};

int K;
// 进入此函数时第i-1列状态为x，第i列状态为y
void dfs(int x, int y, int col, vector<vector<ll> > &d) {
	if (col == K) {
		d[x][y] = 1;
		return;
	}
	// 我的代码
	dfs(x | (1 << col), y, col + 1, d); // 不放置
	dfs(x, y | (1 << col), col + 1, d); // 横向放置
	if (col + 2 <= K) {                 // 竖向放置
		dfs(x | (3 << col), y | (3 << col), col + 2, d);
	}
	/* HihoCoder提示中给的代码
	dfs((x << 1) + 1, y << 1, col + 1, d); // 不放置
	dfs(x << 1, (y << 1) + 1, col + 1, d); // 横向放置
	if (col + 2 <= K) {                    // 竖向放置
		dfs((x << 2) + 3, (y << 2) + 3, col + 2, d);
	}
	*/
}

void getTransMatrix(vector<vector<ll> > &d) {
	dfs(0, 0, 0, d);
}

int main() {
	// freopen("..\\input.txt", "r", stdin);
	cin >> K;
	Matrix m(1<<K, 1<<K); // 转移矩阵
	getTransMatrix(m.a);  // 计算转移矩阵
	Matrix A(1, 1<<K);    // 初始状态
	*(A.a.back().rbegin()) = 1;

	int N; cin >> N;
	for (int t = 0; t < 32; t++) {
		if (N & (1 << t)) A *= m;
		m *= m;
	}
	cout << A.a.back().back() << endl;
}