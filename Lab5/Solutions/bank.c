/************bank.c**********/
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include "bank.h"


 int size = 0;

struct bank* readFromFile(FILE* f)
{
    struct timeval t1,t2;
    double elapsedtime;
    gettimeofday(&t1,NULL);
    struct bank* barr = (struct bank*)malloc(10*sizeof(struct bank));
    
    
    while(1)
    {
        struct bank temp;
        fscanf(f,"\"%ld,%5s,%7s,%5s,%5s\"\n",&temp.card_no,temp.code,temp.date, temp.f_name,temp.l_name);
		barr[size++] = temp;
        if(feof(f))
            break;
        
        if(size % 10 == 0 ){
            struct bank* t = (struct bank*) realloc(barr,(size+10)*sizeof(struct bank) );
	   // free(barr);
	    barr = t;
	}
    }
    //size --;

    gettimeofday(&t2,NULL);
    elapsedtime = (t2.tv_sec - t1.tv_sec)*1000;
    elapsedtime += (t2.tv_usec - t1.tv_usec)/1000;

    FILE* fp = fopen("readtime.txt", "a");
    fprintf(fp, "%lf \n",elapsedtime);
    fclose(fp);
    

    return barr;
}

struct bank* insertInOrder(struct bank* barr,int i)
{
	
    struct bank temp = barr[i];
    int j = i-1;
    while(j>=0 &&(barr[j].card_no > temp.card_no))
    {
        barr[j+1] = barr[j];
        j--;
    }
    barr[j+1] = temp;
    return barr;
 }



struct bank* insertionSort(struct bank* barr, int n)
{
	
    if(n <= 1){
        int a;
        max_stack = &a;
        return barr;
    }
    
    
     barr = insertionSort(barr,n-1);
     barr = insertInOrder(barr, n-1);
    return barr;

}

void calculateStackSpace()
{
    FILE* fp = fopen("stackspace.txt", "a");
    int ss = (int)(max_stack - min_stack);
    fprintf(fp,"%d \n",ss);
    fclose(fp);
}

int getSize()
{
	return size;
}
