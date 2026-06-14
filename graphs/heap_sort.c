#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*#include"heap.h"*/


//HeapSort using extra heap data structure
/*void heapSort(int* nums, int len){*/
/*	Heap* myheap = allocateHeap(true);*/
/*	if(myheap == NULL){*/
/*		printf(" a heap not allocated!\n");*/
/*		return;*/
/*	}*/
/*	*/
/*	for(int i=0; i<len; i++){*/
/*	    insertHeap(myheap, nums[i]);*/
/*	}*/
/*	*/
/*	for(int i=0; i<len; i++){*/
/*	    nums[i] = extractRoot(myheap);*/
/*	}*/
/*	*/
/*	destroyHeap(myheap);*/
/*	return;*/
/*}*/

void printArray(int* nums, int len){
	for(int i=0; i<len; i++){
		printf("%d,", nums[i]);
	}
	printf("\n");
	return;
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}


int min(int* a, int* b){
	if(*a > *b){
		return *b;
	}else{
		return *a;
	}
}

bool compare(bool isMinHeap, int child, int parent){
    if(isMinHeap){
        return child < parent;
    }
    return child > parent;
}


void heapifyDown(int* nums, int i, int heap_size){
	while(true){
		int left_child = (2*i) + 1;
		int right_child = (2*i) + 2;
		
		int best = i;

		if(left_child < heap_size &&
		   compare(false,
			   nums[left_child],
			   nums[best]))
		{
		    best = left_child;
		}

		if(right_child < heap_size &&
		   compare(false,
			   nums[right_child],
			   nums[best]))
		{
		    best = right_child;
		}

		if(best == i){
		    break;
		}

		swap(&nums[i],
		     &nums[best]);

		i = best;
	}
}


//HeapSort in-place i.e. without using extra space.
void heapSortInPlace(int* nums, int len){
	int lnn = (len / 2) - 1;
	for(int i=lnn; i>=0; i--){
		heapifyDown2(nums, i, len);
	}
	//now max heap built, we just swap the last and first, since in max heap the first element is max
	while(len>1){
		swap(&nums[0], &nums[len-1]);
		len--;
		heapifyDown2(nums, 0, len);
	}
	printf("\n");
	return;
}

int main(){
	int nums[5] = {4, 10, 3, 5, 1};
	int len = sizeof(nums) / sizeof(nums[0]);
	printArray(nums, len);
	printf("calling heapsort\n");
	heapSortInPlace(nums, len);
	printArray(nums, len);
	return 0;
}
