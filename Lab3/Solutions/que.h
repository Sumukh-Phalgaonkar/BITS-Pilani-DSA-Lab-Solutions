/*******Queue.h*************/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct task 
{
	int tid;
	int p;
};


struct node 
{
	struct task t;
	struct node* next;
		
};

struct queue 
{
	int size ;
	struct node* head ;
	struct node* tail ;
	
};

struct queue* newQ();

bool isEmptyQ(struct queue* q);

struct queue* delQ(struct queue* q);

struct task frontQ(struct queue* q);

struct queue* addQ(struct queue* q, struct task t);

int lengthQ(struct queue* q);

