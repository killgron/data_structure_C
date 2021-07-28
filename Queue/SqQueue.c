#include "SqQueue.h"

/*
顺序队列：
约定rear总是指向队尾元素
约定front指向当前队中队头元素的前一位置
---------------------------------------------
队空条件：front = rear
队满条件：rear = MaxSize－1
元素e进队：rear++; data[rear]=e;
元素e出队：front++; e=data[front];
---------------------------------------------
*/

void initQueue(SqQueue *Q)
{
    //初始条件：front=rear=-1；
    Q->front = Q->rear = -1;
}
void destroyQueue(SqQueue *Q)
{
    Q->front = Q->rear = -1;
}

Bool isQueueEmpty(SqQueue Q)
{
    if (Q.rear == Q.front)
    {
        return TRUE;
    }
    return FALSE;
}

Status pushBack(SqQueue *Q, ElemType e)
{
    if (Q->rear == MAXSIZE - 1)
    {
        return ERROR; //队列满
    }
    Q->data[++Q->rear] = e;
    return OK;
}

Status pop(SqQueue *Q, ElemType *e)
{
    if (Q->rear == Q->front)
    {
        return ERROR; //队列空
    }
    *e = Q->data[++Q->front];
    return OK;
}

Status getFront(SqQueue *Q, ElemType *e)
{
    if (Q->rear == Q->front)
    {
        return ERROR; //队列空
    }
    *e = Q->data[Q->front + 1];
    return OK;
}

Status getRear(SqQueue *Q, ElemType *e)
{
    if (Q->rear == Q->front)
    {
        return ERROR; //队列空
    }
    *e = Q->data[Q->rear];
    return OK;
}

/*
上面实现的顺序队列有一个很严重的缺陷。按照上述 队满条件：当 Q->rear==Q->front 时,队中还有可能有很多空位置
这种情况不是真正的溢出,称为  假溢出

如何解决该问题呢?
把数组的前端和后端连接起来，形成一个环形的顺序表，即
把存储队列元素的表从逻辑上看成一个环，称为环形队列或循环队列

实际上内存地址一定是连续的，不可能是环形的，这里是通过逻辑方式实现环形队列，也就是
将rear++和front++改为：
rear=(rear+1)%MaxSize
front=(front+1)%MaxSize

---------------------------------------------
循环顺序队列：
约定rear总是指向队尾元素
约定front指向当前队中队头元素的前一位置
---------------------------------------------
队空条件：front = rear
队满条件：(rear+1)%MaxSize = front
元素e进队：rear= (rear+1)%MaxSize; data[rear]=e;
元素e出队：front= (front+1)%MaxSize; e=data[front];
---------------------------------------------
*/

Status cPushBack(SqQueue *Q, ElemType e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front || (Q->rear == MAXSIZE - 1 && Q->front == -1))
    { //循环队列队满
        return ERROR;
    }
    Q->rear = (Q->rear + 1) % MAXSIZE;
    Q->data[Q->rear] = e;
    return TRUE;
}

Status cPop(SqQueue *Q, ElemType *e)
{
    if (Q->rear == Q->front)
    { //循环队列空
        return ERROR;
    }
    Q->front = (Q->front + 1) % MAXSIZE;
    *e = Q->data[Q->front];
    return TRUE;
}
Status cGetFront(SqQueue *Q, ElemType *e)
{
    if (Q->rear == Q->front)
    {
        return ERROR; //队列空
    }
    *e = Q->data[(Q->front + 1) % MAXSIZE];
    return OK;
}
Status cGetRear(SqQueue *Q, ElemType *e)
{
    if (Q->rear == Q->front)
    {
        return ERROR; //队列空
    }
    *e = Q->data[(Q->rear + 1) % MAXSIZE];
    return OK;
}

int main()
{
    SqQueue q;
    initQueue(&q);
    // pushBack(&q, 7);
    // pushBack(&q, 8);
    // pushBack(&q, 9);
    // ElemType e;
    // for (int i = 0; i < 3; i++)
    // {
    //     pop(&q, &e);
    //     printf("Q->front:%d,Q->rear:%d,Q->v:%d\n", q.front, q.rear, e);
    // }

    // Q->front:0,Q->rear:2,Q->v:7
    // Q->front:1,Q->rear:2,Q->v:8
    // Q->front:2,Q->rear:2,Q->v:9

    ElemType e;
    for (int i = 0; i < 12; i++)
    {

        printf("入队列结果:%d\n", cPushBack(&q, i));
    }
    for (int i = 0; i < 12; i++)
    {
        Status r = cPop(&q, &e);
        printf("出队列结果:%d,Q->front:%d,Q->rear:%d,e:%d\n", r, q.front, q.rear, e);
    }
    printf("==========================\n");
    for (int i = 0; i < 4; i++)
    {
        printf("入队列结果:%d\n", cPushBack(&q, i));
    }
    for (int i = 0; i < 10; i++)
    {
        Status r = cPop(&q, &e);
        printf("出队列结果:%d,Q->front:%d,Q->rear:%d,e:%d\n", r, q.front, q.rear, e);
    }

    printf("\n");

    return 0;
}