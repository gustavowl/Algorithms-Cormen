#include <stdio.h>

//array, left, right
int partition(int* a, int l, int r) {
	return -1;
}

//array, left, right
void quicksort(int* a, int l, int r) {
	if (l < r) {
		int q = partition(a, l, r);
		quicksort(a, l, q-1);
		quicksort(a, q+1, r);
	}
}

int main() {
	int array[] = {5, 2, 3, 6, 7, 10, 92};
	quicksort(array, 0, sizeof(array)/sizeof(int) - 1);
	return 0;
}