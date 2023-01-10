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
	
	//set data to new_node, this is done irrespective of the position
	new_node->data=data;
	
	if(head == NULL){
		//if list does not exist, create it.
		//new_node->link = NULL;
		//return new_node;
		goto burgir;
	}
	
	//calculate length of the list
	int len = 0;
	while(head!=NULL){
		len++;
		head = head->link;
	}
	
	//reset head pointer because now it is pointing to null after calculating the length of the list.
	head = saved_head_ptr;
	
	if(position>len){
		printf("bruh, position %d is greater than the size of list\n",position);
		return saved_head_ptr;	
	}

	
	//check position
	switch (position){
		case 0:
			//insert node at the beginning
			burgir:
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

//DELETION OF NODE AT ANY POSITION
struct node *delete_node(int position, struct node *head){
	struct node *saved_head_ptr = head;
	struct node *temp = head;
	struct node *temp1;
	

	switch (position){
		case 0:
			//delete node at the beginning
			head = head->link;
			free(temp);
			return head;
			break;
		default:
			//traverse to nth position
			for(int i = 0; i<position;i++){
				head = head->link;
			}
			//another pointer at n-1 th position
			for(int i = 0; i<position-1;i++){
				temp = temp->link;
			}
			temp1=head;
			printf("temp:%d,head=%d\n",temp->data,head->data);
			temp->link = head->link;
			free(temp1);
			return saved_head_ptr;
			break;
	}
}

int main(){
	//make a linked list now
	struct node *head = NULL;
	head = insert_node(23, NULL, head);
		printList(head);
	head = insert_node(1, 1, head);
		printList(head);
	head = insert_node(9, 2, head);
		printList(head);	
	head = reverse_list(head);
	head = insert_node(5, 0, head);
	printList(head);
}
