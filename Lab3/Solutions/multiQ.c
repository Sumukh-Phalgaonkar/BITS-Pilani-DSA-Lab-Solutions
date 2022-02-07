/********MultiQ.c***********/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "multiQ.h"


//Dynamically allocating the memory to Multi_Queue
multiQ createMQ(int num)
{
	
	multiQ mq = (multiQ)malloc((num)*sizeof(struct queue*));
	int i;
	for(i=0;i<num;i++)
	{
		mq[i]= newQ();
			
	}
	
	return mq;
}


//adding a task to the Multi-Queue
multiQ addMQ(multiQ mq,struct task t)
{
	
	multiQ temp = mq+t.p-1;
	*temp = addQ(*temp,t);
	return mq;
	
}



//Returning the task at the head of queue with max priority
struct task nextMQ(multiQ mq)
{
	int i;
	for(i=0;i<10;i++)
	{
		if(isEmptyQ(mq[i])==true)
			continue;
		else
			return frontQ(mq[i]);
	}
	printf("Empty Multi-Queue\n");
	struct task t ;
	return t;
}


//Deleting the head of queue with max priority
multiQ delNextMQ(multiQ mq)
{
	int i;
	for(i=0;i<10;i++)
	{
		if(isEmptyQ(mq[i])==true)
			continue;
		else
		{
			multiQ temp = mq+i;
			*temp = delQ(*temp);
			return mq;	
		}
	}
	printf("Empty Multi-Queue\n");
	return NULL;
}


//Checking if Multi-Queue is empty
bool isEmptyMQ(multiQ mq)
{
	int i;
	for(i=0;i<10;i++)
	{
		if(isEmptyQ(mq[i])== false)
			return false;		
	}
	return true;
}



//returning the length of Multi-Queue
int sizeMQ(multiQ mq)
{
	int i, sum=0;
	for(i=0;i<10;i++)
	{
		sum+=lengthQ(mq[i]);
	}
	return sum;
}


//Returning the length of queue of priority p
int sizeMQbyPriority(multiQ mq, int p)
{
	return lengthQ(mq[p-1]);
}



//Returning Queue of priority p
struct queue* getQueueFromMQ(multiQ mq, int p)
{
	return mq[p-1];
}






















