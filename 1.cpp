#include <iostream>
#include <ctime>
using namespace std;
#define LL long long
int d[1000];
//int d[] = { -2,11,-4,13,-5,-2 };
int N = 1000;


LL max(LL a, LL b) {
	return a > b ? a : b;
}

int MSSP1(int data[], int n) {
	LL maxx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			LL sum = 0;
			for (int k = i; k <= j; k++) {
				sum += data[k];
			}
			maxx = max(maxx, sum);
		}
	}

	return maxx;
}

int MSSP2(int data[], int n) {
	LL maxx = 0;
	for (int i = 0; i < n; i++) {
		LL sum = 0;
		for (int j = i; j < n; j++) {
			sum += data[j];
			maxx = max(maxx, sum);
		}
		
	}
	return maxx;
}

int MSSP3(int data[], int n) {
	LL maxx = 0;
	LL sum = 0;
	for (int i = 0; i < n; i++) {
		sum = max(0, sum + data[i]);
		maxx = max(maxx, sum);
	}

	return maxx;
}

void setData() {
	srand(time(0));
	for (int i = 0; i < N; i++) {
		d[i] = (rand() % 10) + 1;
		//d[i] = -100;
	}
}

int main() {
	
	//memset(d, 0, sizeof(d));

	//setData();
	
	LL s1 = clock();
	LL res1 = MSSP1(d, N);
	LL e1 = clock();

	LL s2 = clock();
	LL res2 = MSSP2(d, N);
	LL e2 = clock();

	LL s3 = clock();
	LL res3 = MSSP3(d, N);
	LL e3 = clock();

	cout << "T1: " << e1 - s1 << "s" << endl;
	cout << "T2: " << e2 - s2 << "s" << endl;
	cout << "T3: " << e3 - s3 << "s" << endl;
	cout << endl;
	cout << res1 << " " << res2 << " " << res3 << endl;

	system("pause");
	return 0;
}