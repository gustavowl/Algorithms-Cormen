#include <stdio.h>

//array, left, right
int partition(int* a, int l, int r) {
	int k = r; //key index
	int i = l;
	int swap;

	while (i < k) {
		if (a[i] <= a[k])
			i++;
		else {
			//swap
			swap = a[k];
			a[k] = a[i];
			a[i] = a[k - 1];
			a[k - 1] = swap;
			k--;
		}
	}

	return k;
}

//array, left, right
void quicksort(int* a, int l, int r) {
	if (l < r) {
		int q = partition(a, l, r);
		quicksort(a, l, q-1);
		quicksort(a, q+1, r);
	}
}

int is_sorted(int* a, int size) {
	for (int i = 1; i < size; i++) {
		if (a[i-1] > a[i])
			return 0;
	}

	return 1;
}

void print_array(int*a, int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main() {
	int array[] = {2091, 1743, 1065, 1800, 1858, 73, 1945, 2061, 290, 917, 712, 2112, 1480, 1030};
	int size = sizeof(array)/sizeof(int);

	printf("Input array: ");
	print_array(array, size);

	quicksort(array, 0, size - 1);

	printf("Output array: ");
	print_array(array, size);
	printf("Sorted: %s\n", is_sorted(array, size) ? "true" : "false");

	return 0;
}
