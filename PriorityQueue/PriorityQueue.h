#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#include <exception>
#include <stdexcept>
#include <vector>

using std::vector;
using std::underflow_error;
using std::overflow_error;

template <typename T>
inline void exchange(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
}

template <typename T>
class MaxHeap
{
public:
	const T& maximun() const {
		if (data.size() > 0) return data[0];
		else throw underflow_error("");
	}

	T extract_max() {
		if (data.size() <= 0)
			throw underflow_error("");

		T max = data[0];
		data[0] = data[data.size()-1];
		data.pop_back();
		max_heapify(0);

		return max;
	}

	void increase_key(int i, T key) {
		if (i < 0) throw underflow_error("");
		else if (i >= static_cast<int>(data.size())) throw overflow_error("");
		
		if (key < data[i]) return;

		int par = HEAP_PARENT(i);
		while (i > 0 && data[par] < key) {
			data[i] = data[par];
			i = par;
			par = HEAP_PARENT(i);
		}

		data[i] = key;
	}

	void insert(const T &key) {
		data.push_back(key);
		int i = data.size() - 1;
		int par = HEAP_PARENT(i);

		while (i > 0 && data[par] < key) {
			data[i] = data[par];
			i = par;
			par = HEAP_PARENT(i);
		}

		data[i] = key;
	}

private:
	vector<T> data;

	int HEAP_PARENT(int i) const {return (i-1)/2;}
	int HEAP_LEFT(int i) const {return 2*i+1;}
	int HEAP_RIGHT(int i) const {return 2*i+2;}

	void max_heapify(int i) {
		int n = data.size();
		int left = HEAP_LEFT(i);
		int right, largest;

		while (left < n) {
			if (data[left] > data[i]) largest = left;
			else largest = i;

			right = left + 1;
			if (right < n && data[right] > data[largest]) largest = right;

			if (largest != i) {
				exchange(data[i], data[largest]);
				i = largest;
				left = HEAP_LEFT(i);
			}
			else
				break;
		}
	}
};

#endif // _PRIORITY_QUEUE_H_
