#include "SqStack.h"

void initStack(SqStack *S)
{
    // S =(SqStack*)malloc(sizeof(SqStack));
    S->top = -1;
}
void destoryStack(SqStack *S)
{
    free(S);
}
Bool isEmpty(SqStack S)
{
    if (S.top == -1)
    {
        return TRUE;
    }
    return FALSE;
}
Status push(SqStack *S, ElemType e)
{
    if (S->top < MAXSIZE - 1)
    {
        S->data[++S->top] = e;
        return TRUE;
    }
    return FALSE;
}

Status pop(SqStack *S, ElemType *e)
{
    if (S->top > -1)
    {
        *e = S->data[S->top--];
        return TRUE;
    }
    return FALSE;
}

Status getTop(SqStack *S, ElemType *e)
{
    if (S->top > -1)
    {
        *e = S->data[S->top];
        return TRUE;
    }
    return FALSE;
}

int main()
{
    SqStack s;
    ElemType e;
    initStack(&s);
    push(&s, 1);
    push(&s, 2);
   
    return 0;
}