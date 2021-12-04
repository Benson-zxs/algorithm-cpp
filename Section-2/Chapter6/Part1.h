//
// Created by benson.zheng on 2021/11/29.
//

#pragma once

#include "heap.h"

template <typename number>
void max_heapify(heap<number>& A, unsigned i)
{
//  **recursive**

//	unsigned l = left(i);
//	unsigned r = right(i);
//	unsigned largest = 0;
//	if (l < A.heap_size && A[l] > A[i])
//		largest = l;
//	else
//		largest = r;
//	if (r < A.heap_size && A[r] > A[largest])
//		largest = r;
//	if (largest != i)
//	{
//		number temp = A[largest];
//		A[largest] = A[i];
//		A[i] = A[largest];
//		max_heapify(A, largest);
//	}


//  **loop**

	while (i < A.heap_size)
	{
		unsigned l = left(i);
		unsigned r = right(i);
		unsigned largest = 0;
		if (l < A.heap_size && A[l] > A[i])
			largest = l;
		else
			largest = i;
		if (r < A.heap_size && A[r] > A[largest])
			largest = r;
		if (largest != i)
		{
			swap(A[i], A[largest]);
//			number temp = A[largest];
//			A[largest] = A[i];
//			A[i] = temp;
			i = largest;
		}
		else
			return;
	}
}
