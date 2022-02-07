/***ID: 2019A7PS0011P		Name: Sumukh Phalgaonkar  ****/
/*All the functions mentioned in Q1 and Q2 are provided below. The word count of valid strings is stored in size. Optimal tablesize is stored in ts. Optimal basenumber is stored in baseno
Instead of hardcoding these values into hashFunction i have made use of Global variables*/

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>


int size = 0;
int baseno = 0;
int ts = 0;





struct node
{
    int firstindex;
    int count;
    struct node* next;
};


struct hashtable
{
   struct node** table;
   int tablesize;
   int queryingcost;
   int insertioncost;
   int elementcount;

};




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


int collisionCount(char* arr[], int baseno, int tablesize, int size)
{
    int hashvalues[tablesize];
    int i;
   
    for(i=0; i<tablesize; i++)
        hashvalues[i] = 0;

    int count = 0;
    for(i=0; i<size; i++)
    {
        
        int j = hashFunction(arr[i], baseno, tablesize);
        if(hashvalues[j] ==1)
        	count++;
        else
        	hashvalues[j] = 1;
     
    }

    return count;
}



/*This function parses through the text file and parses it into an array of strings*/

char** parsing()
{
    FILE* f = fopen("aliceinwonderland.txt", "r");
    if(f == NULL)
    {
        printf("Error reading the file \n");
        exit(1);
    }
    
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
            //printf("%s ",book[size]);
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





int profiling(char* arr[], int size)
{
    int tablesize[3] = {5000, 50000, 500000};
    int bn[3][6] = {{5557,6673,7901,11820701, 10862081, 15485863},{53269,54059,74731,56221349,63386647,67867967},{848273,849271,904261, 543880109,548033281,553105243}};
    int cc[3][6];
    int i,j;
	int min= collisionCount(arr, bn[0][0], tablesize[0],size);
    for(i=0; i<3; i++)
    {
        for(j=0; j<6; j++)
        {
            cc[i][j] = collisionCount(arr, bn[i][j], tablesize[i], size);

            if(min > cc[i][j])
                min = cc[i][j];

            printf("%d \t",cc[i][j]);
        }
    }

    for(i=0; i<3; i++)
    {
        for(j=0; j<6; j++)
        {
            if(min==cc[i][j])
            {
                printf("\n Indexes of tablesize and tablenos are : %d  and %d respectively \n",i,j);
                printf("TableSize: %d and baseno: %d \n",tablesize[i], bn[i][j]);
                ts = tablesize[i];
                baseno = bn[i][j];
                return tablesize[i];
            }
        }
    }

return 0;
    
}




//Creates and returns empty hashtable
struct hashtable* creation()
{
    struct hashtable* ht = (struct hashtable*)malloc(sizeof(struct hashtable));
    ht -> tablesize = ts; 
    ht -> table = (struct node**)malloc(ts*sizeof(struct node*));
    int i;
    for(i=0; i<ts; i++)
    {
        ht -> table[i] = NULL;
    }
    ht ->elementcount = 0;
    ht ->insertioncost = 0;
    ht ->queryingcost = 0;
    return ht;
}


//Inserts a given string from book into hashtable
void insert(char** book, struct hashtable* ht, int j)
{
    int hv = hashFunction(book[j], baseno, ts);
    ht -> elementcount += 1;
    if(ht -> table[hv] == NULL)
    {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp -> firstindex = j;
        temp -> count = 1;
        temp -> next = NULL;
        ht -> table[hv] = temp;
        
    }
    else
    {
        struct node* temp = ht -> table[hv];

        while((temp->next!=NULL)&& (strcmp(book[j],book[temp -> firstindex])))
        {
            temp = temp -> next;
            ht -> insertioncost ++;
        }
        if(strcmp(book[j],book[temp->firstindex])!=0)
        {
            struct node* temp2 = (struct node*)malloc(sizeof(struct node));
            temp2 -> firstindex = j;
            temp2 -> count = 1;
            temp2 -> next = NULL;
            temp -> next = temp2;
        }
        else
        {
            temp -> count++;
        }
    }

}



//inserts all the strings from book into hashtable 

int insertAll(char** book, struct hashtable* ht)
{
    int i;
    for(i=0; i<size; i++)
    {
        insert(book, ht, i);
    }

    return (ht -> insertioncost);
}




struct node* lookup(struct hashtable* ht, char* s, char** book)
{
    int hv = hashFunction(s, baseno, ts);
    struct node* temp = ht -> table[hv];
    while((temp != NULL) && (strcmp(s,book[temp -> firstindex])))
    {
        ht -> queryingcost += 1;
        temp = temp->next;
    }

    return temp;
}



int lookupall(char** book, struct hashtable* ht, float m) //the value of m needs to be between 0 and 1
{
    int n =(int)(m * size);
    int i;
    ht -> queryingcost = 0;
    for(i=0; i<n; i++)
    {
        struct node* t = lookup(ht, book[i], book);
    }

    return (ht -> queryingcost);
}




int main()
{
	char** book = parsing();
	ts = profiling(book,size);
	printf("\n\n\nCollision count = %d \n\n\n",collisionCount(book,baseno,ts,size));
	struct hashtable* ht = creation();
	printf("\n\n\nInsertion Cost =  %d \n\n\n", insertAll(book,ht));
	printf("\n\n\nQuerying Cost = %d \n\n\n",lookupall(book,ht,1));
		
}
