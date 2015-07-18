#include <iostream>
#pragma warning(disable:4996)
using namespace std;
#define M 19999997
typedef long long ll;

struct Matrix22 {
	ll a11, a12, a21, a22;
	Matrix22(ll _a11 = 0, ll _a12 = 1, ll _a21 = 1, ll _a22 = 1)
		: a11(_a11 % M), a12(_a12 % M), a21(_a21 % M), a22(_a22 % M) {}
	void operator*=(const Matrix22 &r) {
		*this = Matrix22(
			a11 * r.a11 + a12 * r.a21,
			a11 * r.a12 + a12 * r.a22,
			a21 * r.a11 + a22 * r.a21,
			a21 * r.a12 + a22 * r.a22);
	}
};

int main() {
	// freopen("..\\input.txt", "r", stdin);
	int N; cin >> N;
	Matrix22 m, A(1, 0, 0, 1);
	for (int t = 0; t < 32; t++) {
		if (N & (1 << t)) A *= m;
		m *= m;
	}
	cout << A.a22 << endl;
}