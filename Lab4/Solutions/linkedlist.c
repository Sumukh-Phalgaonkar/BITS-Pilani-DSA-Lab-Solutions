#include<stdio.h>
#include<stdlib.h>
#include<time.h> //might be sys/time.h
#include "linkedlist.h"

int heapspace=0;

void* myalloc(int m)
{
    heapspace += m;
    return (malloc(m)); 

}

void myfree(void* p)
{
    free(p);
}

int getheapspace()
{
    return heapspace;
}

struct linkedlist* add( struct linkedlist* ls, int n)
{
    struct node* v = (struct node*)myalloc(sizeof(struct node));
    if(v ==NULL)
    {
        printf("Error assigning new node \n");
        exit(1);
    }
    v -> ele = n;
    v ->next = NULL;
    if( ls ->size == 0)
    {
        ls ->head = v;
        ls ->last =v;
        ls ->size ++;
        return ls;
    }
    
    	(ls ->last)->next = v;
        ls ->last =v;
        ls -> size++;
        return ls;

    
}

struct linkedlist* createList(int n)
{
   
    int i;
    struct linkedlist* ls = (struct linkedlist*)myalloc(sizeof(struct linkedlist));
    if (ls == NULL){
        printf("Error\n");
        exit(1);
    }
    ls ->size = 0;

    for(i=0; i<n; i++)
    {
        srand(time(0));
       ls = add(ls , rand()); 
    }
   

   return ls;
   
}

struct linkedlist* createCycle(struct linkedlist* ls)
{
    srand(time(0));
	printf("Entered CreateCycle\n");
    int toss = rand()%2;
    if(toss == 0)
    {
        //linear linkedlist
	//printf("Linear \n");
        return ls;
    }
    
    
        //cyclic linked list
        srand(time(0));
        int r = rand() % (ls->size);
	//printf("%d cyclic \n",r);
        int i;
        struct node* t = ls -> head;
        for(i=0; i<r-1; i++)
        {	
            t = t ->next;
        }
        (ls ->last)->next = t;
        return ls;
    
}
