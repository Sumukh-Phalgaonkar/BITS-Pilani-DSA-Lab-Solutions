/* driver.c */
#include <stdio.h>
#include "linkedlist.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
// Create a file pointer and open the file read as command line argument.
FILE* fileptr = fopen(argv[1], "r");

// Declare a pointer to a linked list (head) and allocate memory to it.
struct linkedList* head = (struct linkedList*) malloc (sizeof(struct linkedList));

// In a loop read the file and insert elements into the linkedList.
while (1)
	{
	// read the next element and store into the temp variable.
	int temp;
	fscanf(fileptr,"%d",&temp);
	if(feof(fileptr))
		break;
	// insert temp into the linked list.
	insertFirst(head,temp);

	}
// close the file pointer
fclose(fileptr);

// print the linked list.
printList(head);

// delete the first element of the linked list.
deleteFirst(head);

// print the linked list again to check if delete was successful.
printList(head);

//Testing search and delete operations
//printf("%d \n",search(head,32));
//delete(head,32);
//printList(head);


// print the linked list to a new file.
FILE* wf = fopen("Finalresult.txt", "w");
struct node* p = head -> first;
while(p!=NULL)
{
	fprintf(wf,"%d ",p -> element);
	p=p->next;
}
fclose(wf);


}
