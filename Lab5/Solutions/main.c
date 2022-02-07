#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include "bank.h"

int main()
{
	
    FILE* f = fopen("100000","r");
    if (f ==NULL){
        printf("Error File does not exist \n");
        exit(1);
    }

    struct bank* barr = readFromFile(f);
    fclose(f);
	
    int a;
    min_stack = &a;

    struct timeval t1, t2;
    gettimeofday(&t1,NULL);

    barr = insertionSort(barr, getSize());
	
    gettimeofday(&t2, NULL);
    double elapsedtime = (t2.tv_sec - t1.tv_sec)*1000;
    elapsedtime += (t2.tv_usec - t1.tv_usec)/1000;

    FILE* fptr = fopen("Insertionsort_time.txt","a");
    fprintf(fptr,"%lf \n",elapsedtime);
    fclose(fptr);
    
    calculateStackSpace();
   

	free(barr);
    return 0;
}
