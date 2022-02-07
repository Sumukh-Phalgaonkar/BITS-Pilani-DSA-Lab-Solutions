#include<stdio.h>

int collisionCount(char* arr[], int baseno, int tablesize, int size)
{
    int hashvalues[size];
    int i;
    for(i=0; i<size; i++)
        hashvalues[i] = hashFunction(arr[i], baseno, tablesize)

    int count = 0;
    for(i=0; i<size; i++)
    {
        int c=0;
        int j = i-1;
        while(j>=0)
        {
            if(hashvalues[j]==hashvalues[i])
           goto x1;
            j--;
        }
        int k;
        for(k=i+1; k<size; k++)
        {
            if(hashvalue[k] == hashvalue[i])
            c++;
        }

x1:        if(c > count)
            count=c;
        

    }

    return count;
}
