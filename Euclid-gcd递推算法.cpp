#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
long long z;



int Euclid(int a, int b) {
	if(b == 0) return a;
	return Euclid(b, a% b);
}




int main() {
	
	int x, y;
	cin >> x >> y ;
	cout << Euclid(x, y) << endl;
	system ("pause");
	return 0;

}
