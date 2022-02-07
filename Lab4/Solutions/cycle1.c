#include<stdio.h>
#include<stdlib.h>
#include "cycle.h"

int testCyclic(struct linkedlist* ls)
{
    struct node* hare = ls -> head;
    struct node* tort = ls -> head;

    while((hare!=NULL)&&(tort!=NULL)&&((hare->next)!= NULL))
    {
        hare = (hare -> next) -> next;
        tort = tort -> next;
        if(hare == tort)
            return 1;
    }
    return 0;


}
