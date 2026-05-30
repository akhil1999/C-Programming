#ifndef LIST_H
#define LIST_H

#include<stdbool.h>

typedef struct ListNode{
	int data;
	struct ListNode* next;
} ListNode;

typedef struct List{
	struct ListNode* head;
} List;

List* allocateList();
void destroyList(List * list);
void addToList(List* list, int data);
void removeFromList(List* list);
void printList(List* list);
bool hasItem(List* list, int data);
bool isListEmpty(List* list);

#endif
