#include<stdio.h>
#include<string.h>


struct node* lookup(struct hashtable* ht, char* s, char** book)
{
    int hv = hashFunction(s, baseno, ts);
    struct node* temp = ht -> table[hv];
    while((temp != NULL) && (strcmp(s,book[temp -> firstindex])))
    {
        ht -> queryingcost += 1;
        temp = temp->next;
    }

    return temp;
}