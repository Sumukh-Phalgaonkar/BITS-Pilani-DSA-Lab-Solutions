/*****test.c******/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char* argv[])
{
	//printf("argc= %d \n",argc);
	for(int i=0;i<argc;i++)
	{
		printf("%s ",argv[i]);
	}


	//Code for converting string command line arguments to integers
	printf("\n The Integers are : ");
	for(int i=1;i<argc;i++)
	{
		int d = atoi(argv[i]);
		if(d!=0)
		{
			printf("%d \t",d);
		}
		else
		{
			if(strcmp(argv[i],"0")==0)
				printf("%d \t",d);
		}

	}
	
}
