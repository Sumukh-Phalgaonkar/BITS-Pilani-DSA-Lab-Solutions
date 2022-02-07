#include<stdio.h>
#include<stdlib.h>
#include "cycle.h"

int testCyclic(struct linkedlist* ls)
{
	struct node* t = ls -> head;
	struct node* q = (ls -> head) -> next;
	struct node* temp_link = q ->next;

	while((t!=NULL)&&(q!=NULL)&&(temp_link!=NULL))
	{
		if(t == ls -> head)
			t->next = NULL;

		q -> next = t;
		t = q;
		q = temp_link;
		temp_link = q -> next;
		if( q == ls -> head)
			return 1;
	
	}

	return 0;
}
