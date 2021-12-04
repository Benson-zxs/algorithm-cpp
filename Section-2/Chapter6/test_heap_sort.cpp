//
// Created by benson.zheng on 2021/11/29.
//

#include "Part4.h"
#include <iomanip>

int main()
{
	vector<int> test_vec = {5, 13, 2, 25, 7, 17, 20, 8, 4};
	heap<int> test_heap(test_vec);

	heap_sort(test_heap);
	for (int i = 0; i < test_heap.length(); i++)
		cout << setw(2) << test_heap[i] << "\t";
	cout << endl;
	// result:  2       4       5       7       8      13      17      20      25
	return 0;
}
