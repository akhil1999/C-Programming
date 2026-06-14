#ifndef HEAP_H
#define HEAP_H

#include<stdbool.h>
#include<stddef.h>

typedef struct Heap{
	int* data;
	size_t size;
	size_t capacity;
	bool isMinHeap;
} Heap;

Heap* allocateHeap(bool isMinHeap);
void destroyHeap(Heap* heap);
bool insertHeap(Heap* heap, int data);
int extractRoot(Heap* heap);
int peekRoot(Heap* heap);
bool isHeapEmpty(Heap* heap);
void printHeap(Heap* heap);
void heapifyUp(Heap* heap, int i);
void heapifyDown(Heap* heap, int i, int heap_size);
void swap(int* a, int* b);

#endif
