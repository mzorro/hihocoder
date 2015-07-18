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

	Matrix(int m, int n, ll *b) : m(m), n(n) {
		a = vector<vector<ll> >(m, vector<ll>(n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = b[i*n+j];
			}
		}
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

int main() {
	ll b[] = { // ×ªÒÆ¾ØÕó
		0, 0, 0, 0, 0, 0, 0, 1,
		0, 0, 0, 0, 0, 0, 1, 0,
		0, 0, 0, 0, 0, 1, 0, 0,
		0, 0, 0, 0, 1, 0, 0, 1,
		0, 0, 0, 1, 0, 0, 0, 0,
		0, 0, 1, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 1, 0, 0, 1, 0,
	};
	Matrix m(8, 8, b);
	ll a[] = { // ³õÊ¼×´Ì¬
		0, 0, 0, 0, 0, 0, 0, 1,
	};
	Matrix A(1, 8, a);

	freopen("..\\input.txt", "r", stdin);
	int N; cin >> N;
	for (int t = 0; t < 32; t++) {
		if (N & (1 << t)) A *= m;
		m *= m;
	}
	cout << A.a.back().back() << endl;
}