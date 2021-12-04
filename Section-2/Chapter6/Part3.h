//
// Created by benson.zheng on 2021/11/29.
//

#pragma once

#include "Part1.h"

template <typename number>
void build_max_heap(heap<number>& A)
{
	A.heap_size = A.length();
	for (int i = A.length() / 2 - 1; i >= 0; i--)
		max_heapify(A, i);
}
