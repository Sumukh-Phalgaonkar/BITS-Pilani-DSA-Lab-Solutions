#include<stdio.h>

//need to modify - hardcode baseno and tablesize
int hashFunction(char* s, int baseno, int tablesize)
{
    int i, hval = 0;
    for(i=0; *(s+i)!= '\0';i++)
    {
        hval += (int)*(s+i);
    }
    hval = (hval % baseno) % tablesize;

    return hval;
}

int main()
{
	char* arr[] = {"abracadabra","abracadabra","abracadabra"};
    printf("%d \n",collisionCount(arr, 100, 100,3));
    return 0;
}
