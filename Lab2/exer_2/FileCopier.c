/******* File copier *********/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	if(argc!=3){
		printf("Error!! Please provide the name of source and Destination File in this order\n");
		exit(1);
	}
	char* source = argv[1];
	char* destination = argv[2];
	FILE* rf = fopen(source,"r");
	FILE* wf = fopen(destination, "w");
	if(rf==NULL){
		printf("Source file not present \n");
		exit(1);
	}
	if(wf==NULL){
		printf("Error!!!\n");
		exit(1);
	}
	char c = '1';
	while(c!=EOF)
	{
		c=fgetc(rf);
		fputc(c,wf);
	}

	fclose(rf);
	fclose(wf);
	printf("Files copied successfully\n");
	exit(0);


}
