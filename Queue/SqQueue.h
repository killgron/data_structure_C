#include "define.h"
#define MAXSIZE 10
typedef int ElemType;

typedef struct 
{
    ElemType data[MAXSIZE];
    int rear,front;
}SqQueue;

//顺序队列
void initQueue(SqQueue*);
void destroyQueue(SqQueue*);
Bool isQueueEmpty(SqQueue);
Status pushBack(SqQueue*,ElemType);
Status pop(SqQueue*,ElemType*);
Status getFront(SqQueue*,ElemType*);
Status getRear(SqQueue*,ElemType*);

//循环顺序队列 Circular Queue
Status cPushBack(SqQueue*,ElemType);
Status cPop(SqQueue*,ElemType*);
Status cGetFront(SqQueue*,ElemType*);
Status cGetRear(SqQueue*,ElemType*);
