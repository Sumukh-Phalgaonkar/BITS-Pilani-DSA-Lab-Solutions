/**********bank.h**************/
#include<stdio.h>

struct bank
{
    long card_no;
    char code[5];
    char date[7];
    char f_name[5];
    char l_name[5];
};

int* min_stack;
int* max_stack;
//int size = 0;

struct bank* readFromFile(FILE* f);
struct bank* insertInOrder(struct bank* barr,int i);
struct bank* insertionSort(struct bank* barr, int n); 
void calculateStackSpace();
int getSize();


