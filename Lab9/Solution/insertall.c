#include<stdio.h>
#include<stdlib.h>

int insertAll(char** book, struct hashtable* ht)
{
    int i;
    for(i=0; i<size; i++)
    {
        insert(book, ht, i);
    }

    return (ht -> insertioncost);
}