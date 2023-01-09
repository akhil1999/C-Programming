#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

void printList(struct node *head){
	while(head!=NULL){
		printf("%d,",head->data);
		head = head->link;
	}
	printf("\n");
}

//INSERTION OF NODE AT ANY POSITION
struct node *insert_node(int data, int position, struct node *head){
	struct node *saved_head_ptr = head;
	struct node *new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data=data;
	
	if(head == NULL){
		//if list does not exist, create it.
		new_node->data =  data;
		new_node->link = NULL;
		return new_node;
	}
	
	//calculate length of the list
	int len = 0;
	while(head!=NULL){
		len++;
		head = head->link;
	}
	head = saved_head_ptr;
	
	printf("len:%d\n", len);
	
	if(position>len){
		printf("bruh, position %d is greater than the size of list\n",position);
		return saved_head_ptr;	
	}

	
	//check position
	switch (position){
		case 0:
			//insert node at the beginning
			new_node->link = head;
			head = new_node;
			return head;
			break;
		default:
			//insert node at the nth position
			if(position==len){
				//insert node at the end
				
				//traverse to end of the list.
				while(head->link!=NULL){
					head = head->link;
				}
				head->link = new_node;
				new_node->link = NULL;
			}else{
				//insert node anywhere but first and last position
				//go to position - 1 node.
				for(int i=0;i<position-1;i++){
					head = head->link;
				}
				new_node->link = head->link;
				head->link = new_node;
			}
	}
	return saved_head_ptr;	
}

int main(){
	//make a linked list now
	struct node *head = NULL;
	head = insert_node(420, NULL, head);
		printList(head);
	head = insert_node(69, 0, head);
		printList(head);
	head = insert_node(12, 0, head);
		printList(head);	
	head = insert_node(1156, 4, head);
	printList(head);
}
