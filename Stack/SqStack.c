#include "SqStack.h"

/*
栈空条件：top=-1
栈满条件：top=MaxSize-1
进栈e操作：top++; 将e放在top处
退栈操作：从top处取出元素e; top--;
*/

void initStack(SqStack *S)
{
    // S =(SqStack*)malloc(sizeof(SqStack));
    S->top = -1;
}
void destoryStack(SqStack *S)
{
    S->top = -1;
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