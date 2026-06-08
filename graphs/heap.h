#ifndef HEAP_H
#define HEAP_H

#include<stdbool.h>
#include<stddef.h>

typedef struct MaxHeap{
	int* data;
	size_t size;
	size_t capacity;
} Heap;

Heap* allocateHeap();
void destroyHeap(Heap* heap);
bool insertHeap(Heap* heap, int data);
int extractMax(Heap* heap);
int peekMax(Heap* heap);
bool isHeapEmpty(Heap* heap);
void printHeap(Heap* heap);

#endif
