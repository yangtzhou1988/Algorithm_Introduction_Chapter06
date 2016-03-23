#ifndef _HEAP_SORT_H_
#define _HEAP_SORT_H_

template <typename T>
inline void exchange(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
}

inline int HEAP_PARENT(int i)
{
	return (i-1)/2;
}

inline int HEAP_LEFT(int i)
{
	return 2*i+1;
}

inline int HEAP_RIGHT(int i)
{
	return 2*i+2;
}

template <typename T>
void MaxHeapify(T d[], int n, int i)
{
	int left = HEAP_LEFT(i);
	int right, largest;

	while (left < n) {
		if (d[left] > d[i]) largest = left;
		else largest = i;

		right = left + 1;
		if (right < n && d[right] > d[largest]) largest = right;

		if (largest != i) {
			exchange(d[i], d[largest]);
			i = largest;
			left = HEAP_LEFT(i);
		}
		else
			break;
	}
}

template <typename T>
void BuildMaxHeap(T d[], int n)
{
	for (int i = n/2-1; i >= 0; --i)
		MaxHeapify(d, n, i);
}

template <typename T>
void heap_sort(T d[], int n)
{
	BuildMaxHeap(d, n);

	for (int i = n-1; i > 0; --i) {
		exchange(d[0], d[i]);
		MaxHeapify(d, i, 0);
	}
}

#endif // _HEAP_SORT_H_
