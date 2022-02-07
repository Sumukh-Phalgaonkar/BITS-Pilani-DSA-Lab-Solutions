#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include "cycle.h"

int main()
{   
    struct timeval t1, t2;
    double tt;
    gettimeofday(&t1, NULL);
    int n = 2200000;
    struct linkedlist* ls = createList(n);
    ls = createCycle(ls);
    int a = testCyclic(ls);
    gettimeofday(&t2, NULL);
    printf("%d \n",a);
    FILE* f = fopen("output.txt", "a");
    tt = (t2.tv_sec - t1.tv_sec)*1000;
    tt+=(t2.tv_usec -t1.tv_usec)/1000;
    fprintf(f,"%d %lf %d\n",n, tt, getheapspace());
    fclose(f);
    return 0;
}


