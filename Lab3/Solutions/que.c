/**********Queue.c*************/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "que.h"


//Creating a new queue
struct queue* newQ()
{
	struct queue* q = (struct queue*)malloc(sizeof(struct queue));
	if(q == NULL)
	{
		printf("Error in producing new Queue \n");
	
	}
	q-> size = 0;	
	return q;
}


//Checking if a queue is empty
bool isEmptyQ(struct queue* q)
{
	if((q->size)==0){
	      	return true;
	}
	else{
		return false;
	}
}



//Deleting from Queue
struct queue* delQ(struct queue* q)
{
	struct node* temp = q->head;
	q->head = temp->next;
	q->size--;
	temp->next=NULL;
	free(temp);
	return q;
}


//Reading from a queue
struct task frontQ(struct queue* q)
{
	struct node* p = q->head;
	struct task temp = p -> t; //Check this line
	return temp;
}



//Adding to a queue
struct queue* addQ (struct queue* q, struct task t)
{
	
	struct node* v = (struct node*)malloc(sizeof(struct node));
	if(v==NULL)
		printf("Error in creating a new node \n");
	v->t = t;
	v->next = NULL;
	if(isEmptyQ(q)== true)
	{
		q->head = v;
		q->tail = v;
		
	}
	
	else
	{
		(q->tail)->next = v;
		q->tail = v;
	}
	q->size++;
	
	return q;
}



//Finding the size of the queue
int lengthQ(struct queue* q)
{
	return q->size;
}


























