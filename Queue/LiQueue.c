#include "LiQueue.h"

//队空条件：Q->rear=Q->front=NULL;

void initQueue(LiQueue *Q)
{
    // Q=(LiQueue*)malloc(sizeof(LiQueue));
    Q->front = Q->rear = NULL;
}

void destroyQueue(LiQueue *Q)
{
    QNode *p = Q->front, *r;
    if (p != NULL)
    {
        r = p->next;
        while (r != NULL)
        {
            QNode *t = r;
            r = r->next;
            free(t);
        }
    }
    free(p);
    Q->front=Q->rear=NULL;
    // free(Q);
}
// Bool isQueueEmpty(LiQueue);
Status pushBack(LiQueue *Q, ElemType e)
{
    QNode *p = (QNode *)malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    if (Q->front == NULL)
    {
        Q->front = Q->rear = p;
    }
    else
    { //if(Q->front==Q->rear)
        Q->rear->next = p;
        Q->rear = p;
    }
    return OK;
}
Status pop(LiQueue *Q, ElemType *e)
{
    if (Q->front == NULL)
    {
        return ERROR;
    }
    QNode *p = Q->front;
    if (Q->front == Q->rear)
    {
        Q->front = Q->rear = NULL;
    }
    else
    {
        Q->front = Q->front->next;
    }
    *e = p->data;
    free(p);
    return TRUE;
}
// Status getFront(LiQueue*,ElemType*);
// Status getRear(LiQueue*,ElemType*);

int main()
{
    LiQueue q;
    ElemType e;
    initQueue(&q);
    for (int i = 0; i < 10; i++)
    {
        pushBack(&q, i);
    }
    destroyQueue(&q);
    for (int i = 0; i < 10; i++)
    {
        Status r = pop(&q, &e);
        printf("r:%d------e:%d\n", r, e);
    }
}