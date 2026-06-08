#include<stdio.h>
#include<stdlib.h>
#include"heap.h"

Heap* allocateHeap(){
	Heap* myheap = malloc(sizeof(Heap));
	if(myheap == NULL){
		printf("heap allocate fail malloc()!\n");
		return NULL;
	}
	myheap->data = NULL;
	myheap->size = 0;
	myheap->capacity = 0;
	return myheap;
}

void destroyHeap(Heap* heap){
	if(heap == NULL){
		printf("can't destroy non existent heap!\n");
		return;
	}
	free(heap->data);
	free(heap);
	return;
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

bool compare(Heap* heap, int child, int parent){

    if(heap->isMinHeap){
        return child < parent;
    }

    return child > parent; // Max Heap
}

bool insertHeap(Heap* heap, int data){
	if(heap == NULL){
		printf("heap not allocated, pls allocate heap!\n");
		return false;
	}
	if(heap->data == NULL){
		heap->data = malloc(sizeof(int));
		if(heap->data == NULL){
			printf("malloc failed\n");
			return false;
		}
		heap->capacity = 1;
		heap->size = 1;
		heap->data[0] = data;
		return true;
	}
	if(heap->size == heap->capacity){
		int* temp = realloc(heap->data, 2*heap->capacity*sizeof(int));
		if(temp == NULL){
			printf("realloc failed!\n");
			return false;
		}
		heap->data = temp;
		heap->data[heap->size] = data;
		heap->size++;
		heap->capacity = 2 * heap->capacity;
	}else{
		heap->data[heap->size] = data;
		heap->size++;
	}
	int i = heap->size - 1;
	int parent = (i - 1) / 2;
	while(i>0 && compare(heap,
              heap->data[i],
              heap->data[parent])){
		swap(&heap->data[i], &heap->data[parent]);
		i = parent;
		parent = (i - 1) / 2;
	}
	return true;
}
void heapifyDown(Heap* heap, int i){
	while(true){
		int left_child = (2*i) + 1;
		int right_child = left_child + 1;
		
		int best = i;

		if(left_child < (int)heap->size &&
		   compare(heap,
			   heap->data[left_child],
			   heap->data[best]))
		{
		    best = left_child;
		}

		if(right_child < (int)heap->size &&
		   compare(heap,
			   heap->data[right_child],
			   heap->data[best]))
		{
		    best = right_child;
		}

		if(best == i){
		    break;
		}

		swap(&heap->data[i],
		     &heap->data[best]);

		i = best;
	}
}

int extractRoot(Heap* heap){
	if(heap == NULL || heap->data == NULL || heap->size == 0){
		printf("heap not allocated\n");
		return -1;
	}
	int data = heap->data[0];
	//since data extracted, remove the max and replace it
	heap->data[0] = heap->data[heap->size-1];
	heap->size--;
	heapifyDown(heap, 0);
	return data;	
}

int peekMax(Heap* heap){
	if(heap == NULL){
		printf("heap not allocated\n");
		return -1;
	}
	if(heap->data == NULL){
		printf("heap allocated but empty\n");
		return -1;
	}
	return heap->data[0];
}

bool isHeapEmpty(Heap* heap){
	if(heap == NULL || heap->data == NULL || heap->size == 0){
		return true;
	}
	return false;
}

void printHeap(Heap* heap){
	if(heap == NULL || heap->data == NULL){
		printf("empty heap\n");
		return;
	}
	for(size_t i=0; i<heap->size; i++){
		printf("%d,", heap->data[i]);
	}
	printf("\n");
	return;
}

int main(){
	Heap* myheap = allocateHeap();
	myheap->isMinHeap  = true;
	insertHeap(myheap,100);
	insertHeap(myheap,70);
	insertHeap(myheap,80);
	insertHeap(myheap,25);
	insertHeap(myheap,50);
	printHeap(myheap);
	insertHeap(myheap,95);
	printHeap(myheap);
	extractRoot(myheap);
	printHeap(myheap);
	destroyHeap(myheap);
	return 0;
}
