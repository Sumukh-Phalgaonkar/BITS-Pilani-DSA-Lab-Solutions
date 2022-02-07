#include "stack.h"
#include<stdio.h>


void push(struct linkedList* head, int ele)
{
	insertFirst(head,ele);
	printf("%d pushed \n",ele);

}

struct node* pop(struct linkedList* head)
{
	struct node* temp = deleteFirst(head);
	if(temp==NULL)
		printf("Stack empty\n");
	else
		printf("%d popped\n",temp->element);
	return temp;
}
