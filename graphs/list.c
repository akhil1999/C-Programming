#include<stdio.h>
#include<stdlib.h>
#include"list.h"

void addToList(List* list, int data){
	if(list == NULL){
		printf("List not allocated!\n");
		return;
	}
	ListNode* new_node = malloc(sizeof(ListNode));
	if(new_node == NULL){
		printf("list node malloc() failed!\n");
		return;
	}
	new_node->data = data;
	if(list->head == NULL){
		new_node->next = NULL;
		list->head = new_node;
		return;
	}
	new_node->next = list->head;
	list->head = new_node;
	return;
}

void removeFromList(List* list){
	if(list->head == NULL){
		printf("cannot remove from empty list\n");
		return;
	}
	ListNode* temp = list->head;
	list->head = list->head->next;
	free(temp);
	return;
}

void printList(List* list){
	ListNode* temp = list->head;
	while(temp!=NULL){
		printf("%d,", temp->data);
		temp = temp->next;
	}
	printf("\n");
	return;
}

bool hasItem(List* list, int data){
	ListNode* temp = list->head;
	while(temp!=NULL){
		if(data == temp->data) return true;
		temp = temp->next;
	}
	return false;
}

bool isListEmpty(List* list){
	if(list->head != NULL){
		return false;
	}
	return true;
}

List* allocateList(){
	List* mylist = malloc(sizeof(List));
	if(mylist == NULL){
		printf("list allocation malloc() failed!\n");
		return NULL;
	}
	mylist->head = NULL;
	return mylist;
}

void destroyList(List * list){
	ListNode* temp = list->head;
	while(temp != NULL){
		ListNode* next = temp->next;
		free(temp);
		temp = next;
	}
	free(list);
	return;
}

/*int main(){*/
/*	List* mylist = allocateList();*/
/*	if(mylist == NULL){*/
/*		printf("list did not allocate!\n");*/
/*		return -1;*/
/*	}*/
/*	addToList(mylist, 1);*/
/*	addToList(mylist, 2);*/
/*	addToList(mylist, 3);*/
/*	printList(mylist);*/
/*	printf("isListEmpty?:%d\n",isListEmpty(mylist));*/
/*	removeFromList(mylist);*/
/*	removeFromList(mylist);*/
/*	removeFromList(mylist);*/
/*	printf("isListEmpty?:%d\n",isListEmpty(mylist));*/
/*	destroyList(mylist);*/
/*	return 0;*/
/*}*/
