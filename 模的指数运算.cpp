#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
long long z;

long long modexp(long long x, long long y, long long N) {
	if (y ==0) return 1;
	z = modexp(x, y/2, N);
	if (y % 2 == 0) return (z * z) % N;
	else return (x * z * z ) % N;
}



int main() {
	
	int x, y, N;
	cin >> x >> y >> N;
	cout << modexp(x, y, N) << endl;
	system ("pause");
	return 0;

}
