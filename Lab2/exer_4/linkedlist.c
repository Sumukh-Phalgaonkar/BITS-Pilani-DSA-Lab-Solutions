/* linkedlist.c */
#include "linkedlist.h"
#include<stdio.h>

void insertFirst(struct linkedList* head, int ele){

//create a node
struct node *link = (struct node*) malloc (sizeof(struct node)); 
/* by this
you are creating a node whose address is being stored in the link pointer. */

link->element = ele;
//point it to old first node

link->next = head->first;
//point first to new first node

head -> first = link;
head -> count ++;

}

//delete first item
struct node* deleteFirst(struct linkedList* head){
// exercise to implement this operation.

	struct node *tmp = head -> first;
	head -> first = tmp -> next;
	head -> count--;
	//printf("Deleted element is %d \n",tmp->element);
	tmp->next=NULL;
	return tmp;
}




//display the list
void printList(struct linkedList* head)
{
	struct node *ptr = head->first;
	printf("\n[ ");
	//start from the beginning
	while(ptr != NULL){
	printf("%d, ", ptr->element);
	ptr = ptr->next;
	}
	printf(" ]\n");
}



//search for given element
int search(struct linkedList* head, int ele)
{
	struct node* ptr= head -> first;
	while(ptr!=NULL)
	{
		if(ele == ptr -> element)
			return 1;
		ptr=ptr->next;
	}
	return 0;
}


struct node* delete(struct linkedList* head, int ele)
{

	struct node* p1 = head -> first;
	struct node* p2 = p1->next;
	if(p1->element == ele)
		return deleteFirst(head);
	while(p2!=NULL)
	{
		if(ele == p2 -> element)
		{
			p1->next=p2->next;
			p2->next=NULL;
			printf("%d Deleted \n",p2->element);
		       	head -> count --;
			return p2;	

		}
		p1=p1->next;
		p2=p2->next;
	}
	printf("%d Not found\n",ele);
	return p2;
}



















