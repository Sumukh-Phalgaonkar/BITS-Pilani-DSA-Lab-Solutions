#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

int main(int argc, char* argv[])
{
	struct linkedList* head = (struct linkedList*) malloc(sizeof(struct linkedList));
	FILE* fp = fopen(argv[1],"r");

	while(1)
	{
		int temp;
		fscanf(fp,"%d",&temp);
		if(feof(fp))
			break;
		push(head,temp);
	}
	fclose(fp);
	printf("\n Printing the stack :");
	printList(head);
	while(head->first != NULL)
	{
		pop(head);
	}
}
