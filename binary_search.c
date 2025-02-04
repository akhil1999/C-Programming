#include<stdio.h>

int binarySearchIterative(int *array, int len, int target){
	int low = 0;
	int high = len - 1;
	while(low<=high){
		int mid = low + (high - low) / 2;
		if(array[mid] == target) return mid;
		else if(target > array[mid]) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}

int binarySearchRecursive(int *array, int start, int end, int target){
	if(start>end) return -1;
	int mid = start + (end - start) / 2;
	if(array[mid] == target) return mid;
	else if(array[mid] < target) return binarySearchRecursive(array, mid+1, end, target);
	else return binarySearchRecursive(array, start, mid-1, target);
}

int binarySearchIterativePtr(int *array, int len, int target){
	int *start = array;
	int *end = array + len - 1;
	while(start<=end){
		int *mid = start + (end - start) / 2;
		if(*mid == target) return (mid - array);
		else if(target > *mid) start = mid + 1;
		else end = mid - 1;
	}
	return -1;
}

int binarySearchRecursivePtr(int *array, int *start, int *end, int target){
	if(start>end) return -1;
	int *mid = start + (end - start) / 2;
	if(*mid == target) return (mid - array);
	else if(*mid > target) return binarySearchRecursivePtr(array, start, mid-1, target);
	else return binarySearchRecursivePtr(array, mid+1, end, target);
}

void main(){
	int a[10] = {1,2,3,4,56,70,90,101, 200, 300};
	int *end = (a+9);
	printf("Enter element to search:");
	int target = 0;
	scanf("%d", &target);
	printf("position:%d\n", binarySearchIterative(a, 10, target));
	printf("position:%d\n", binarySearchRecursive(a, 0, 9, target));
	printf("position:%d\n", binarySearchIterativePtr(a, 10, target));
	printf("position:%d\n", binarySearchRecursivePtr(a, a, end, target));
}
