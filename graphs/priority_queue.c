#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"priority_queue.h"

void swap(PQNode* a, PQNode* b){
	//not simple int swap, cleanly copy each field?
	PQNode temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void heapifyPQDown(PQ* pq, int i, int pq_size){
	while(true){
		unsigned int left_child = (2 * i) + 1;
		unsigned int right_child = (2 * i) + 2;
		int best = i;
		
		if(left_child < pq_size && pq->data[left_child].distance < pq->data[best].distance){
			best = left_child;
		}
		
		if(right_child < pq_size && pq->data[right_child].distance < pq->data[best].distance){
			best = right_child;
		}
		
		if(best == i){
			break;
		}
		
		swap(&pq->data[best], &pq->data[i]);
		i = best;
	}
	return;
}

void heapifyPQUp(PQ* pq, int i){
	int parent = (i - 1) / 2;
	while(i>0 && pq->data[i].distance < pq->data[parent].distance){
		swap(&pq->data[i], &pq->data[parent]);
		i = parent;
		parent = (i - 1) / 2;		
	}
	return;
}

void push(PQ* pq, int vertex, int distance){
	if(pq == NULL){
		printf("PQ is not allocated\n");
		return;
	}
	
	if(pq->data == NULL){
		pq->data = malloc(1 * sizeof(PQNode));
		if(pq->data == NULL){
		    printf("malloc failed\n");
		    return;
		}
		pq->data[0].vertex = vertex;
		pq->data[0].distance = distance;
		pq->size = 1;
		pq->capacity = 1;
		return;
	}
	
	if(pq->size == pq->capacity){
		PQNode* temp = realloc(pq->data, 2 * sizeof(PQNode) * pq->capacity);
		if(temp == NULL){
			printf("PQ realloc failed\n");
			return;
		}
		pq->capacity = 2 * (pq->capacity);
		pq->data = temp;
		pq->data[pq->size].vertex = vertex;
		pq->data[pq->size].distance = distance;
		pq->size++;
	}else{
		pq->data[pq->size].vertex = vertex;
		pq->data[pq->size].distance = distance;
		pq->size++;
	}
	heapifyPQUp(pq, pq->size-1);
	return;
}

PQNode pop(PQ* pq){
	//remove the highest priority item
	PQNode temp = {-1, -1};
	if(isPQEmpty(pq)){
		return temp;
	}
	temp = pq->data[0];
	pq->size--;
	pq->data[0].vertex = pq->data[pq->size].vertex;
	pq->data[0].distance = pq->data[pq->size].distance;
	heapifyPQDown(pq, 0, pq->size);
	return temp;
	
}

PQNode peek(PQ* pq){
	//just return the hightest priority item, don't remove it
	PQNode temp = pq->data[0];
	if(isPQEmpty(pq)){
		printf("PQ is empty");
		return temp;
	}
	return pq->data[0];
}

bool isPQEmpty(PQ* pq){
	if(pq == NULL || pq->size == 0){
		return true;
	}
	return false;
}

void destroyPQ(PQ* pq){
	if(pq == NULL){
		printf("PQ already empty\n");
		return;
	}
	free(pq->data);
	free(pq);
	return;
}

void printPQ(PQ* pq){
	if(isPQEmpty(pq)){
		printf("pq empty nothing to print\n");
		return;
	}
	for(unsigned int i=0; i<pq->size; i++){
		printf("(%d:%d),", pq->data[i].vertex, pq->data[i].distance);
	}
	printf("\n");
	return;
}

PQ* allocatePQ(){
	PQ* pq = malloc(sizeof(PQ));
	if(pq == NULL){
		printf("failed to malloc PQ\n");
		return NULL;
	}
	pq->data = NULL;
	pq->size = 0;
	pq->capacity = 0;
	return pq;
}

/*int main(int argc, char* argv[]){*/
/*	PQ* pq = allocatePQ();*/
/*	push(pq, 'A', 1);*/
/*	push(pq, 'B', 4);*/
/*	push(pq, 'C', 0);*/
/*	printPQ(pq);*/
/*	pop(pq);*/
/*	printPQ(pq);*/
/*	destroyPQ(pq);*/
/*	return 0;*/
/*}*/
