#include <stdbool.h>

struct bstNode{
	int data;
	struct bstNode* left;
	struct bstNode* right;
};

struct node{
	struct bstNode* bstNodePtr;
	struct node* link;
};

void enqueue(struct bstNode* bstNodePtr);
void printQueue();
struct bstNode* dequeue();
bool isQueueEmpty();
