#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Merge(int* array, int low, int mid, int high) {
	int i = low;
	int j = mid + 1;
	int k = 0;
	int* array2 = new int[high - low + 1];

	while(i <= mid && j <= high) {
		if (array[i] <= array[j]) {
			array2[k++] = array[i++];	
		} else {
			array2[k++] = array[j++];
		}
	}

	while(i <= mid) {
		array2[k++] = array[i++];
	}

	while (j <= high) {
		array2[k++] = array[j++];
	}

	for(k = 0, i = low; i <= high; i++, k++) {
		array[i] = array2[k];
	}

}

void MergePass(int * array, int gap, int length) {
	int i = 0;

	for (i = 0; i + 2 * gap < length; i += 2 * gap) {
		Merge(array, i, i + gap - 1, i + 2 * gap - 1);
	}

	if (i + gap - 1 < length) {
		Merge(array, i, i +gap - 1, length - 1);
	}
}


int* MergeSort(int* list, int len) {
	
	for (int gap = 1;gap  < 10; gap = 2 * gap) {
		MergePass(list, gap, len);
	}
	return list;
}


int main() {
	int N;
	cin >> N;
	int* l = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> l[i];
	}

	int* list = MergeSort(l,N);
	
	for (int i = 0; i < N; i ++ ) {
		cout << list[i] << " ";
	}

	system ("pause");
	return 0;

}
