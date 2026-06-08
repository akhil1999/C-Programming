#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"vector.h"

Vector* allocateVector(){
	Vector* myVector = malloc(sizeof(Vector));
	if(myVector == NULL){
		printf("malloc failed to allocate vector\n");
		return NULL;
	}
	myVector->vector = NULL;
	myVector->size = 0;
	myVector->capacity = 0;
	return myVector;
}

void destroyVector(Vector* vector){
	free(vector->vector);
	free(vector);
}


bool pushBack(Vector* vector, int data){
	if(vector->vector == NULL){
		printf("vector null case\n");
		vector->vector = malloc(10 * sizeof(int));
		if(vector->vector == NULL){
			printf("vector allocate failed!\n");
			return false;
		}
		vector->capacity = 10;
		vector->size = 1;
		vector->vector[0] = data;
		return true;
	}
	if(vector->capacity > vector->size){
		printf("vector cap ok case\n");
		vector->vector[vector->size] = data;
		vector->size++;
		return true;
	}else{
		printf("vector realloc case\n");
		int* temp = realloc(vector->vector, 2 * (vector->capacity*sizeof(int)));
		if(temp == NULL){
			return false;
		}
		vector->vector = temp;
		vector->capacity = 2 * vector->capacity;
		vector->vector[vector->size] = data;
		vector->size++;
		return true;
	}
}

int popBack(Vector* vector){
	if(vector->vector == NULL || vector->size == 0){
		printf("vector empty, cannot popBack()!\n");
		return -69;
	}
	int data = vector->vector[vector->size-1];
	vector->size--;
	return data;
}

int at(Vector* vector, size_t index){
	if(index < vector->size){
	printf("at %lu is %d\n", index, vector->vector[index]);
	return vector->vector[index];
	}else{
		return -69;
	}
}

void printVector(Vector* vector){
	for(int i=0; i<vector->size; i++){
		printf("%d,", vector->vector[i]);
	}
	printf("\n");
	return;
}

bool isVectorEmpty(Vector* vector){
	if(vector == NULL || vector->vector == NULL || vector->size == 0){
		printf("vector not allocated\n");
		return true;
	}
	return false;
}

int main(){
	Vector* myvector = allocateVector();
	for(int i=0; i<10; i++){
		pushBack(myvector, i);
	}
	printVector(myvector);
	pushBack(myvector,20);
	printVector(myvector);
	printf("%d\n", popBack(myvector));
	printVector(myvector);
	destroyVector(myvector);
	return 0;
}
