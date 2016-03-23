#include <iostream>
#include "HeapSort.h"

using std::cout;
using std::endl;

int main()
{
	int a[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };

	heap_sort(a, sizeof(a)/sizeof(int));

	for (int i = 0; i < sizeof(a)/sizeof(int); ++i)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}
