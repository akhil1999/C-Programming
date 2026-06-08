#include<stdio.h>
#include<stdlib.h>
#include"heap.h"

void heapSort(int* nums, int len){
	Heap* myheap = allocateHeap();
	if(myheap == NULL){
		printf(" a heap not allocated!\n");
		return;
	}
	myheap->isMinHeap = false;
	
	for(int i=0; i<len; i++){
	    insertHeap(myheap, nums[i]);
	}
	
	for(int i=len-1; i>=0; i--){
	    nums[i] = extractRoot(myheap);
	}
	
	destroyHeap(myheap);
	return;
}

void printArray(int* nums, int len){
	for(int i=0; i<len; i++){
		printf("%d,", nums[i]);
	}
	printf("\n");
	return;
}

int main(){
	int nums[5] = {4, 10, 3, 5, 1};
	int len = sizeof(nums) / sizeof(nums[0]);
	printArray(nums, len);
	heapSort(nums, len);
	printArray(nums, len);
	return 0;
}
