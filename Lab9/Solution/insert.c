#include<stdio.h>
#include<stdlib.h>

void insert(char** book, struct hashtable* ht, int j)
{
    int hv = hashFunction(book[j], baseno, ts);
    ht -> elementcount += 1;
    if(ht -> table[hv] == NULL)
    {
        struct node* temp = (struct node*)malloc(sizeof(struct node))
        temp -> firstindex = j;
        temp -> count = 1;
        temp -> next = NULL;
        ht -> table[hv] = temp;
        
    }
    else
    {
        struct node* temp = ht -> table[hv];

        while((temp->next!=NULL)&& (strcmp(book[j],book[temp -> firstindex]))
        {
            temp = temp -> next;
            ht -> insertioncost ++;
        }
        if(strcmp(book[j],book[temp->firstindex])!=0)
        {
            struct node* temp2 = (struct node*)malloc(sizeof(struct node));
            temp2 -> firstindex = j;
            temp2 -> count = 1;
            temp2 -> next = NULL;
            temp -> next = temp2;
        }
        else
        {
            temp -> count++;
        }
    }

}