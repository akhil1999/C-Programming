#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

void enqueue(Queue* q, int data){
	QueueNode* new_node = malloc(sizeof(QueueNode));
	if(new_node == NULL){
		printf("problem enqueuing, malloc() failed!\n");
		return;
	}
	new_node->data = data;
	if(q->front == NULL){
		q->front = q->rear = new_node;
		q->front->next = NULL;
		return;
	}
	q->rear->next = new_node;
	q->rear = q->rear->next;
	q->rear->next = NULL;
	return;
}

int dequeue(Queue* q){
	QueueNode* temp = q->front;
	if(temp == NULL){
		return -1;
	}
	q->front = q->front->next;
	if(q->front == NULL){
		q->rear = NULL;
	}
	int data = temp->data;
	free(temp);
	return data;
}

void printQueue(Queue* q){
	QueueNode* temp = q->front;
	while(temp!=NULL){
		printf("%d,", temp->data);
		temp = temp->next;
	}
	printf("\n");
	return;
}

bool isEmpty(Queue* q){
	if(q->front != NULL){
		return false;
	}
	return true;
}

int frontQueue(Queue* q){
	if(q->front!=NULL){
		return q->front->data;
	}
	return -1;
}

Queue* allocateQueue(){
	Queue* myqueue = malloc(sizeof(Queue));
	if(myqueue == NULL){
		printf("Allocating queue malloc() failed!\n");
		return NULL;
	}
	myqueue->front = NULL;
	myqueue->rear = NULL;
	return myqueue;
}

void destroyQueue(Queue* q){
    QueueNode* temp = q->front;
    while(temp != NULL){
        QueueNode* next = temp->next;
        free(temp);
        temp = next;
    }
    free(q);
}

/*int main(){*/
/*	Queue* myqueue = allocateQueue();*/
/*	if(myqueue == NULL){*/
/*		printf("Couldn't allocate queue!\n");*/
/*		return -1;*/
/*	}*/
/*	enqueue(myqueue, 1);*/
/*	enqueue(myqueue, 2);*/
/*	enqueue(myqueue, 3);*/
/*	printQueue(myqueue);*/
/*	printf("isEmpty:%d\n", isEmpty(myqueue));*/
/*	printf("dequeue:%d\n", dequeue(myqueue));*/
/*	printf("dequeue:%d\n", dequeue(myqueue));*/
/*	printf("dequeue:%d\n", dequeue(myqueue));*/
/*	printQueue(myqueue);*/
/*	printf("isEmpty:%d\n", isEmpty(myqueue));*/
/*	destroyQueue(myqueue);*/
/*}*/
