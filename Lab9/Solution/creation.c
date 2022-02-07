#include<stdio.h>
#include<stdlib.h>

struct node
{
    int firstindex;
    int count;
    struct node* next;
}


struct hashtable
{
   struct node** table;
   int tablesize;
   int queryingcost;
   int insertioncost;
   int elementcount;

}

struct hashtable* creation()
{
    struct hashtable* ht = (struct hashtable*)malloc(sizeof(hashtable));
    ht -> tablesize = ts; // make tablesize from profiling global
    ht -> table = (struct node**)malloc(ts*sizeof(struct node*));
    int i;
    for(i=0; i<ts; i++)
    {
        ht -> table[i] = NULL;
    }
    ht ->elementcount = 0;
    ht ->insertioncost = 0;
    ht ->queryingcost = 0;
    return ht;
}

