#include<stdio.h>
#include<string.h>

int lookupall(char** book, struct hashtable* ht, float m)
{
    int n =(int)(m * size);
    int i;
    ht -> queryingcost = 0;
    for(i=0; i<n; i++)
    {
        struct node* t = lookup(ht, book[i], book);
    }

    return (ht -> queryingcost);
}