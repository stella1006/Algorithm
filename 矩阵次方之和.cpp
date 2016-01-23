#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct  {
	int mat[31][31];
} Matrix;

int n, m;
Matrix ONE;


Matrix mul(Matrix A, Matrix B) { //æÿ’Ûœ‡≥À
	
	Matrix C ;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			C.mat[i][j] = 0;
			for (int k = 1; k <= n; k++) {
				
				C.mat[i][j] = (A.mat[i][k] * B.mat[k][j] + C.mat[i][j])%m ;
			}

		}

	}
	return C;
}

Matrix add(Matrix A, Matrix B) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			A.mat[i][j] += B.mat[i][j];
			A.mat[i][j] %= m;
		}

	}
	return A;
}

Matrix powmul(Matrix A, int k) {
	if (k == 1) return A;
	Matrix B = powmul(A, k / 2);
	B = mul(B, B);
	if (k % 2) B = mul(B, A);
	return B;
}




Matrix series_powmul(Matrix A, int k) {
	if (k == 1) return A;
	if (k % 2 == 0) {
		Matrix B = series_powmul(A, k / 2);
		return mul(add(powmul(A, k / 2), ONE), B);
	} else {
		Matrix B = series_powmul(A, k / 2);
		Matrix C = powmul(A, (k+1) / 2);
		return add(C, mul(B, add(C, ONE)));
	}


}


int main() {
	
	int k;
	cin >> n >> k >> m;
	
	Matrix A;
	for (int i = 1; i <= n; i++) {
		ONE.mat[i][i] = 1;
		for (int j = 1; j <= n; j++) {
			
			cin >> A.mat[i][j] ;
		}

	}

	Matrix temp = series_powmul(A, k);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << (temp.mat[i][j]) % m;
			if (j != n) cout << " ";
		}
		cout << endl;

	}
	

	


	system ("pause");
	return 0;

}
