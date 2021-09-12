#include <stdio.h>	//basic i/o
#include <stdlib.h> //for dynamic allocation of memory

struct Node	//LinkedList Node Data Structure Definition
{
int data;
struct Node *next;
};

struct Node *head; 	//head pointer of linked list

void Print(struct Node *p) 	//function for printing linked list(recursive in nature)
{
if(p==NULL)
	{
	return;
	}
	printf(" %d",(*p).data);
	Print((*p).next);
}

void InsertPos(int x, int pos)	//function to insert Node at specific position
{
struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
struct Node *temp1=head;
(*temp).data=x;
if(pos == 1)
	{
	(*temp).next=head;
	head=temp;
	return;
	}
for(int i=0;i<pos-2;i++)
	{
	temp1=(*temp1).next;
	}
(*temp).next=(*temp1).next;
(*temp1).next=temp;
}

void DeletePos(int pos)	//function to delete a Node at specific position
{
struct Node *temp=head;
if(pos == 1)
	{
	head=(*temp).next;
	free(temp);
	return;
	}
for(int i=0;i<pos-2;i++)
	{
	temp=(*temp).next;
	}
	struct Node *temp1=(*temp).next;
	(*temp).next=(*temp1).next;
	free(temp1);
}

int main()		//main function
{
head=NULL;	//head initialised to NULL so that we can assume linked list is empty/doesn't exist at first
InsertPos(1,1);	//insert 1 @ position 1;
InsertPos(2,2);	//insert 2 @ position 2;
InsertPos(3,3);	//insert 3 @ position 3;
Print(head);		//print linked list
printf("\n");	
DeletePos(2);		//delete node at position 2
Print(head);
}
