#include<stdio.h>

int binarySearchFirstOccurence(int *array, int len, int target){
	int low = 0;
	int high = len - 1;
	int result = -1;
	while(low<=high){
		int mid = low + (high - low) / 2;
		if(array[mid] == target){
			result = mid;
			high = mid - 1;
		}
		else if(array[mid] > target) high = mid - 1;
		else low = mid + 1;
	}
	return result;
}

int binarySearchLastOccurence(int *array, int len, int target){
	int low = 0;
	int high = len - 1;
	int result = -1;
	while(low<=high){
		int mid = low + (high - low) / 2;
		if(array[mid] == target){
			result = mid;
			low = mid + 1;
		}
		else if(array[mid] > target) high = mid - 1;
		else low = mid + 1;
	}
	return result;
}

int findCount(int *array, int len, int target){
	int first = binarySearchFirstOccurence(array, len, target);
	int last = binarySearchLastOccurence(array, len, target);
	return (last - first + 1);
}

void main(){
	int a[10] = {0,2,3,4,4,4,90,101, 200, 300};
	int *end = (a+9);
	printf("Enter element to search:");
	int target = 0;
	scanf("%d", &target);
	printf("First Occurrence:%d\n", binarySearchFirstOccurence(a, 10, target));
	printf("Last Occurrence:%d\n", binarySearchLastOccurence(a, 10, target));
	printf("Count:%d\n", findCount(a, 10, target));
}
