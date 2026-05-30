#ifndef QUEUE_H
#define QUEUE_H

#include<stdbool.h>

typedef struct QueueNode{
	int data;
	struct QueueNode* next;
} QueueNode;

typedef struct Queue{
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* allocateQueue();
void destroyQueue(Queue* q);
void enqueue(Queue* q, int data);
int dequeue(Queue* q);
void printQueue(Queue* q);
bool isEmpty(Queue* q);
int frontQueue(Queue* q);

#endif
