#include<stdio.h>

struct node
{
    int value;
    struct node* left;
    struct node* right;
    int hinfo : 3;
};

