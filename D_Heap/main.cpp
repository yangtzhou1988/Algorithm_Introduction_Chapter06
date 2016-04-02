#include <iostream>
#include "DHeap.h"

using std::cout;
using std::endl;

int main()
{
	DMaxHeap<int, 3> dmh;
	dmh.insert(1);
	dmh.insert(2);
	dmh.insert(3);
	dmh.insert(4);
	dmh.insert(5);
	dmh.insert(6);
	dmh.insert(7);

	dmh.increase_key(4, 7);

	dmh.erase(1);

	int i = dmh.extract_max();

	return 0;
}
