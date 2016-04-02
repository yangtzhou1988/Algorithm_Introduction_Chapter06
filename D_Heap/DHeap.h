#ifndef _D_HEAP_H_
#define _D_HEAP_H_

#include <stdexcept>
#include <vector>

using std::underflow_error;
using std::overflow_error;
using std::vector;

template <typename T>
inline void exchange(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
}

template <typename T, unsigned int d>
class DMaxHeap {
public:
	const T& maximun() const {
		if (data.size() > 0) return data[0];
		else throw underflow_error("");
	}

	T extract_max() {
		if (data.size() <= 0)
			throw underflow_error("");

		T max = data[0];
		data[0] = data[data.size() - 1];
		data.pop_back();
		max_d_heapify(0);

		return max;
	}

	void increase_key(int i, T key) {
		if (i < 0) throw underflow_error("");
		else if (i >= static_cast<int>(data.size())) throw overflow_error("");

		if (key < data[i]) return;

		int par = DHEAP_PARENT(i);
		while (i > 0 && data[par] < key) {
			data[i] = data[par];
			i = par;
			par = DHEAP_PARENT(i);
		}

		data[i] = key;
	}

	void insert(const T &key) {
		data.push_back(key);
		int i = data.size() - 1;
		int par = DHEAP_PARENT(i);

		while (i > 0 && data[par] < key) {
			data[i] = data[par];
			i = par;
			par = DHEAP_PARENT(i);
		}

		data[i] = key;
	}

	void erase(int i) {
		int n = data.size();

		if (i < 0) throw underflow_error("");
		else if (i >= n) throw overflow_error("");

		if (i == n - 1)
			data.pop_back();
		else {
			if (data[n-1] <= data[i]) {
				data[i] = data[n-1];
				data.pop_back();
				max_d_heapify(i);
			}
			else {
				T last = data[n-1];
				data.pop_back();
				increase_key(i, last);
			}
		}
	}

private:
	vector<T> data;

	int DHEAP_PARENT(int i) const { return (i-1)/d; }
	int DHEAP_CHILD(int i, int j) const { return i*d+j+1; }

	void max_d_heapify(int i) {
		int n = data.size();
		int child = DHEAP_CHILD(i, 0);
		int largest;

		while (child < n) {
			largest = i;
			for (int j = child; j < child+static_cast<int>(d) && j < n; ++j)
				if (data[j] > data[largest]) largest = j;

			if (largest != i) {
				exchange(data[i], data[largest]);
				i = largest;
				child = DHEAP_CHILD(i, 0);
			}
			else
				break;
		}
	}
};

#endif // _D_HEAP_H_
