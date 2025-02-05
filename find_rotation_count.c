#include<stdio.h>

int findRotationCount(int *array, int len){
	int low = 0;
	int high = len - 1;
	while(low<=high){
		int mid = low + (high - low) / 2;
		int prev = (mid + len - 1) % len;
		int next = (mid + 1) % len;
		if(array[low] <= array[high]) return low;
		else if(array[mid]<=array[prev] && array[mid]<=array[next]) return mid;
		else if(array[mid]<=array[high]) high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}

void main(){
	int array[10] = {5,6,7,8,9,10,1,2,3,4};
	printf("Rotation count:%d\n", findRotationCount(array, 10));
}
