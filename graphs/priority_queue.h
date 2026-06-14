#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

typedef struct PQNode{
	int vertex;
	int distance;
}PQNode;

typedef struct PQ{
	PQNode* data;
	size_t size;
	size_t capacity;
}PQ;

PQ* allocatePQ();

void destroyPQ(PQ* pq);

void push(PQ* pq, int vertex, int distance);
PQNode pop(PQ* pq);
PQNode peek(PQ* pq);

bool isPQEmpty(PQ* pq);

#endif
