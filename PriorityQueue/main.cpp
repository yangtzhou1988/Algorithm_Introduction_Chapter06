#include <iostream>
#include "PriorityQueue.h"

using std::cout;
using std::endl;

int main()
{
	MaxHeap<int> mh;

	mh.insert(1);
	mh.insert(2);
	mh.insert(3);
	mh.insert(4);
	mh.insert(5);
	mh.insert(6);
	mh.insert(7);

	mh.increase_key(6, 10);

	int m = mh.extract_max();
	m = mh.extract_max();

	return 0;
}
