/***********multiQ.h************/
#include<stdio.h>
#include<stdbool.h>
#include "que.h"

typedef struct queue** multiQ;

multiQ createMQ(int num);

multiQ addMQ(multiQ mq, struct task t);

struct task nextMQ(multiQ mq);

multiQ delNextMQ(multiQ mq);

bool isEmptyMQ(multiQ mq);

int sizeMQ(multiQ mq);

int sizeMQbyPriority(multiQ mq, int p);

struct queue* getQueueFromMQ(multiQ mq, int p);
