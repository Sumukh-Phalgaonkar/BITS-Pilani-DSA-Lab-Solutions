/*********linkedlist.h*********/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


struct node
{
    int ele;
    struct node* next;
};

struct linkedlist
{
    struct node* head;
    int size;
    struct node* last;
};

struct linkedlist* createList(int n);

struct linkedlist* createCycle(struct linkedlist* ls);

void* myalloc(int m);

void myfree(void* p);

struct linkedlist* add( struct linkedlist* ls, int n);

int getheapspace();

