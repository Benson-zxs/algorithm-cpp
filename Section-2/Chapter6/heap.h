//
// Created by benson.zheng on 2021/11/29.
//

#ifndef ALGORITHMS_HEAP_H
#define ALGORITHMS_HEAP_H

#endif //ALGORITHMS_HEAP_H

#include <iostream>
#include <vector>
using namespace std;

inline unsigned left(unsigned i) { return i*2 + 1; }
inline unsigned right(unsigned i) { return i*2 + 2; }
inline unsigned parent(unsigned i) { return (i + 1)/2 - 1; }

template <typename number>
inline void swap(number& a, number& b)
{
	number temp = a;
	a = b;
	b = temp;
}

template <typename number>
class heap
{
public:
	vector<number> array;
	unsigned heap_size = array.size();

	heap() = default;

	explicit heap(vector<number> A)
	{
		this->array = A;
		this->heap_size = A.size();
	}

	number& operator[](unsigned i) { return this->array[i]; }
	unsigned length() { return this->array.size(); }
};
