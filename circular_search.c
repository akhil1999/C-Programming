#include<stdio.h>

int circularSearch_variation1(int *array, int len, int target){
	int low = 0;
	int high = len - 1;
	while(low<=high){
		int mid = low + (high - low) / 2;
		if(array[mid]==target) return mid;
		if(array[mid]<=array[high]){
			if(target>array[mid] && target <= array[high]){
				low = mid + 1;
			}else{
				high = mid - 1;
			}
		}else{
			if(target>=array[low] && target < array[mid]){
				high = mid - 1;
			}else{
				low = mid + 1;
			}
		}		
	}
	return -1;
}

int circularSearch_variation2(int *array, int len, int target){
	int low = 0;
	int high = len - 1;
	while(low<=high){
		int mid = low + (high - low) / 2;
		if(array[mid]==target) return mid;
		if(array[low]<=array[mid]){
			if(target>=array[low] && target<array[mid]){
				high = mid - 1;
			}else{
				low = mid + 1;
			}
		}else{
			if(target>array[mid] && target <= array[high]){
				low = mid + 1;
			}else{
				high = mid - 1;
			}
		}		
	}
	return -1;
}

int circularSearch_variation1_ptr(int *array, int *len, int *target){
	int *low = array;
	int *high = array + *len - 1;
	while(low<=high){
		int *mid = low + (high - low) / 2;
		if(*mid == *target) return (mid - array);
		if(*low<=*mid){
			if(*target>=*low && *target<*mid){
				high = mid - 1; 
			}else{
				low = mid + 1;
			}
		}else{
			if(*target>*mid && *target<=*high){
				low = mid + 1;
			}else{
				high = mid -1;
			}
		}
	}
	return -1;
}

int circularSearch_variation2_ptr(int *array, int *len, int *target){
	int *low = array;
	int *high = array + *len - 1;
	while(low<=high){
		int *mid = low + (high - low) / 2;
		if(*mid == *target) return (mid-array);
		if(*mid<=*high){
			if(*target>*mid && *target<=*high){
				low = mid + 1;
			}else{
				high = mid - 1;
			}
		}else{
			if(*target>=*low && *target<*mid){
				high = mid - 1;
			}else{
				low = mid + 1;
			}
		}
	}
	return -1;
}

int main(){
	int array[8] = {12, 14,18,21,3,6,8,9};
	int target = 0;
	int len = 8;
	printf("Enter element to search in circular array:");
	scanf("%d", &target);
	int *target_ptr = &target;
	int *len_ptr = &len; 
	printf("Index of target:%d\n", circularSearch_variation1(array, 8, target));
	printf("Index of target:%d\n", circularSearch_variation2(array, 8, target));
	printf("Index of target:%d\n", circularSearch_variation1_ptr(array, len_ptr, target_ptr));
	printf("Index of target:%d\n", circularSearch_variation2_ptr(array, len_ptr, target_ptr));
	return 0;
}
