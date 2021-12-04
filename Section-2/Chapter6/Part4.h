//
// Created by benson.zheng on 2021/11/29.
//

#pragma once

#include "Part3.h"

template <typename number>
void heap_sort(heap<number>& A, bool ascending = true)
{
	build_max_heap(A);
	for (int i = A.length() - 1; i > 0; i--)
	{
		swap(A[0], A[i]);
//		number temp = A[0];
//		A[0] = A[i];
//		A[i] = temp;
		A.heap_size -= 1;
		max_heapify(A, 0);
	}
	if (!ascending)
	{
		for (int i = 0; i < A.length()/2; i++)
		{
			swap(A[i], A[A.length() - i - 1]);
//			number temp = A[i];
//			A[i] = A[A.length() - i - 1];
//			A[A.length() - i - 1] = temp;
		}
	}
}
