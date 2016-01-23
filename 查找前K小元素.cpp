#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findKth(int * s, int n, int k) {
	int low = 0; 
	int high = n - 1;
	int pivot = s[0];
	while(low < high) {
		while (low < high && s[high] >= pivot) {
			--high;
		}
		s[low] = s[high];
		while (low < high && s[low] <= pivot)
			++low;
		s[high] = s[low];

	}
	s[low] = pivot;
	if (low == k - 1) return s[low];
	else if (low > k - 1) return findKth(s, low, k);
	else return findKth(s + low + 1, n - low - 1, k - low - 1);
}


int main() {
	int N, k;
	cin >> N >> k;
	int* l = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> l[i];
	}

	int p = findKth(l, N, k);
	cout << p << endl;

	system ("pause");
	return 0;

}
