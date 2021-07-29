#include "define.h"

typedef int ElemType;

//数据节点
typedef struct Node
{
    ElemType data;
    struct Node *next;
} QNode;

//链队头节点
typedef struct Queue
{
    struct Node *front;
    struct Node *rear;
} LiQueue;

//链队
void initQueue(LiQueue*);
void destroyQueue(LiQueue*);
Bool isQueueEmpty(LiQueue);
Status pushBack(LiQueue*,ElemType);
Status pop(LiQueue*,ElemType*);
Status getFront(LiQueue*,ElemType*);
Status getRear(LiQueue*,ElemType*);