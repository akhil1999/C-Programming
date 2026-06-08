#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector{
	int* vector;
	size_t size;
	size_t capacity;
}Vector;

Vector* allocateVector();
void destroyVector(Vector* vector);
bool pushBack(Vector* vector, int data);
int popBack(Vector* vector);
int at(Vector* vector, size_t index);
void printVector(Vector* vector);
bool isVectorEmpty(Vector* vector);

#endif
