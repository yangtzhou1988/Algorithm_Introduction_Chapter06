#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

template <typename T>
struct HeapElem {
	T elem;
	int index;
};

template <typename T>
bool operator<(HeapElem<T> &x, HeapElem<T> &y)
{
	return (x.elem < y.elem);
}

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
void min_heapify(T d[], int n, int i)
{
	int left = HEAP_LEFT(i);
	int right, smallest;

	while (left < n) {
		if (d[left] < d[i]) smallest = left;
		else smallest = i;

		right = left + 1;
		if (right < n && d[right] < d[smallest]) smallest = right;

		if (smallest != i) {
			exchange(d[i], d[smallest]);
			i = smallest;
			left = HEAP_LEFT(i);
		}
		else
			break;
	}
}

template <typename T>
void build_min_heap(T d[], int n)
{
	for (int i = n/2-1; i >= 0; --i)
		min_heapify(d, n, i);
}

template <typename T>
void merge_list(list<T> l[], int k, list<T> &r)
{
	r.clear();

	if (l == NULL || k <= 0)
		return;

	list<T>::iterator *it = new list<T>::iterator[k];
	for (int i = 0; i < k; ++i)
		it[i] = l[i].begin();

	HeapElem<T> *min_heap = new HeapElem<T>[k];
	int min_heap_size = 0;
	for (int i = 0; i < k; ++i) {
		if (!l[i].empty()) {
			min_heap[min_heap_size].elem = *(it[i]);
			min_heap[min_heap_size].index = i;
			++it[i];
			min_heap_size++;
		}
	}

	build_min_heap(min_heap, min_heap_size);

	while (min_heap_size > 0) {
		int i = min_heap[0].index;
		r.push_back(min_heap[0].elem);

		if (it[i] != l[i].end()) {
			min_heap[0].elem = *(it[i]);
			it[i]++;
		}
		else {
			min_heap_size--;
			if (min_heap_size > 0) min_heap[0] = min_heap[min_heap_size];
		}

		min_heapify(min_heap, min_heap_size, 0);
	}

	delete[] it;
	delete[] min_heap;
}

int main()
{
	list<int> l[4];

	l[0].push_back(-1);
	l[0].push_back(10);
	l[0].push_back(11);

	l[1].push_back(2);
	l[1].push_back(5);
	l[1].push_back(30);
	l[1].push_back(100);

	l[2].push_back(3);
	l[2].push_back(5);

	//l[3].push_back(4);

	list<int> r;

	merge_list(l, 4, r);

	for (list<int>::iterator i = r.begin(); i != r.end(); ++i)
		cout << *i << " ";
	cout << endl;

	return 0;
}
