#include <stdio.h>
#include <stdlib.h>

//insertion of node in doubly linked list at any position
//deletion of node in doubly linked list at any position

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

struct node *head;
struct node *tail;

int cal_len(struct node *head){
	int counter = 0;
	while(head!=NULL){
		counter++;
		head = head->next;
	}
	return counter;
}

void printList(struct node *head){
	while(head!=NULL){
		printf("%d,", head->data);
		head = head->next;
	}
	printf("\n");
	return;
}

void printListReverse(struct node *head){
	while(head!=NULL){
		printf("%d,", head->data);
		head = head->prev;
	}
	printf("\n");
	return;
}

//function that inserts a node at nth position
struct node *insert_node(int data, int position, struct node *head){
	struct node *saved_head_ptr = head;
	struct node *new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = data;
	
	int len = cal_len(head);
	
	if(len == 0 || head == NULL){
		new_node->prev = NULL;
		new_node->next = NULL;
		return new_node;
	}
	
	if(position > len){
		printf("Bruh, position is greater than the length of the list\n");
		return saved_head_ptr;
	}
	
	new_node->next = NULL;
	new_node->prev = head;
	head->next = new_node;
	return head;
}

struct node *insert_at_head(int data, struct node *head){
	struct node *saved_head_ptr = head;
	struct node *new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = data;
	if(head == NULL){
		head = new_node;
		tail = new_node;
		return;
	}
	
	new_node->next = head;
	new_node->prev = NULL;
	head->prev = new_node;
	head = new_node;
	
	while(saved_head_ptr!=NULL){
		tail = saved_head_ptr;
		saved_head_ptr = saved_head_ptr->next;
	}
		
	return head;
}

struct node *insert_at_tail(int data, struct node *tail){
	struct node *new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = data;
	tail->next = new_node;
	new_node->prev = tail;
	new_node->next = NULL;
	tail = new_node;
	return tail;
}


void main(){
//	head = insert_node(1, NULL, head);
	head = insert_at_head(1,head);
	head = insert_at_head(2,head);
	head = insert_at_head(5,head);
	head = insert_at_head(6,head);
	printList(head);
	printListReverse(tail);
	tail = insert_at_tail(8,tail);
	printList(head);	
	printListReverse(tail);
	printf("tail:%d\n", tail->data);
}

