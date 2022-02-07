#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

//make int size global 

char** parsing()
{
    FILE* f = fopen("aliceinwonderland.txt", "r");
    if(f == NULL)
    {
        printf("Error reading the file \n");
        exit(1);
    }
    int size = 0;
    int max = 1000;
    char** book = (char**)malloc(max*sizeof(char*));
    int i;
    for(i=0; i<max; i++)
    {
        book[i] = (char*)malloc(20*sizeof(char));
    }
    
    char* temp = (char*)malloc(20*sizeof(char));
    while(1)
    {
    	fscanf(f,"%s ",temp);
    	if(feof(f))
    	break;
    	
        int flag = 0;
        for(i=0; i< strlen(temp); i++)
        {
        	
            if(isalpha(temp[i]) == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            strcpy(book[size], temp);
            printf("%s ",book[size]);
            size++;
        }

        if(size ==  max)
        {
            max += 1000;
           book = (char**)realloc(book, max*sizeof(char*));
           int j;
           for(j=size;j<max;j++)
           {
               book[j] = (char*)malloc(20*sizeof(char));
           }

        }
          

    }

    printf("word count = %d \n",size);
    fclose(f);
    return book;
}


int main()
{
    parsing();
    return 0;
}
