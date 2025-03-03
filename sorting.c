#include<stdio.h>
#include<stdlib.h>

void printArray(int *array, int len){
	for(int i=0; i<len; i++){
		printf("%d,", array[i]);	
	}
	printf("\n");
	return;
}

void bubbleSort(int *array, int len){
	for(int k=1;k<len-1;k++){
		int flag = 0;
		for(int i=0; i<=len-k-1; i++){
			if(array[i]>array[i+1]){
				flag = 1;
				int temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
			}
		}
		if(flag == 0){
			break;
		}
	}
	return;
}

void selectionSort(int *array, int len){
	for(int i=0; i<len-2; i++){
		int iMin = i;
		for(int j=i+1;j<len;j++){
			if(array[j]<array[iMin]){
				iMin = j;
			}
		}
		int temp = array[i];
		array[i] = array[iMin];
		array[iMin] = temp;
	}
	return;
}

void insertionSort(int *array, int len){
	for(int i=1; i<len; i++){
		int value = array[i];
		int hole = i;
		while(hole>0 && array[hole-1]>value){
			array[hole] = array[hole-1];
			hole = hole - 1;
		}
		array[hole] = value;
	}
}

void mergeCore(int *left, int *right, int *array, int left_len, int right_len, int len){
	int i=0,j=0,k=0;
	while(i<left_len && j<right_len){
		if(left[i] <= right[j]){
			array[k] = left[i];
			i++;
		}else{
			array[k] = right[j];
			j++;
		}
		k++;
	}
	while(i<left_len){
		array[k] = left[i];
		i++;
		k++;
	}
	while(j<right_len){
		array[k] = right[j];
		j++;
		k++;
	}
	return;
}

void mergeSort(int *array, int len){
	if(len<2) return;
	int mid = len / 2;
	int *left = (int*) malloc(mid);
	int *right = (int*) malloc(mid);
	for(int i=0; i<mid; i++){
		left[i] = array[i];
	}
	for(int i=mid;i<len;i++){
		right[i-mid] = array[i];
	}
	mergeSort(left, mid);
	mergeSort(right, mid);
	mergeCore(left, right, array, mid, mid, len);
	free(left);
	free(right);
	return;
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

int partition(int *array, int start, int end, int len){
	int random_pivot = (rand()%9);
	int pivot = array[random_pivot];
	int pIndex = start;
	for(int i=start; i<end; i++){
		if(array[i] <= pivot){
			swap(array+i, array+pIndex);
			pIndex++;
		}
	}
	swap(array+pIndex, array+random_pivot);
	return pIndex;
}

void quickSort(int *array, int start, int end, int len){
	if(start < end){
		int pIndex = partition(array,start,end,len);
		quickSort(array, start, pIndex-1, len);
		quickSort(array, pIndex+1, end, len);
	}
}

//driver code, main function
int main(){
	int a[9] = {2,4,1,6,8,5,3,7,9};
	int len = sizeof(a)/sizeof(int);
	printArray(a,len);
/*	selectionSort(a,len);*/
/*	bubbleSort(a,len);*/
/*	insertionSort(a,len);*/
/*	mergeSort(a, len);*/
	quickSort(a, 0, 8, len);
	printArray(a,len);
/*	printf("len:%d\n", len);*/
/*	test(a);*/
/*	scanf("%d", &b);*/
	return 0;
}
