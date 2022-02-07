#include<stdio.h>

int profiling(char* arr[], int size)
{
    int tablesize[3] = {5000, 50000, 500000};
    int baseno[3][6] = {{5557,6673,7901,11820701, 10862081, 15485863},{53269,54059,74731,56221349,63386647,67867967},{848273,849271,904261, 543880109,548033281,553105243}};
    int cc[3][6];
    int i,j,min= collisionCount(arr, baseno[0][0], tablesize[0],size);
    for(i=0; i<3; i++)
    {
        for(j=0; j<6; j++)
        {
            cc[i][j] = collisionCount(arr, baseno[i][j], tablesize[i], size);

            if(min > c[i][j])
                min = c[i][j];

            printf("%d \t",c[i][j]);
        }
    }

    for(i=0; i<3; i++)
    {
        for(j=0; j<6; j++)
        {
            if(min==cc[i][j])
            {
                printf("\n Indexes of tablesize and tablenos are : %d  and %d respectively \n",i,j);
                printf("TableSize: %d and baseno: %d \n",tablesize[i], baseno[i][j]);
                return tablesize[i];
            }
        }
    }

return 0;
    
}