#include "LiStack.h"

/*
栈空条件：s->next=NULL
栈满条件：不考虑
进栈e操作：将包含e的节点插入到头节点之后
退栈操作：取出头节点之后节点的元素并删除
*/

//建立一个空栈s。创建链栈的头节点，并将其next域置为NULL。
void initStack(LiStack *S)
{
    *S = (LiNode *)malloc(sizeof(LiNode) * MAXSIZE);
    (*S)->next = NULL;
}

void destoryStack(LiStack *S)
{
    LiNode *p = *S, *q = (*S)->next;
    while (q != NULL)
    {
        free(p);
        p = q;
        q = p->next;
    }
    free(p);
}
Bool isEmpty(LiStack S)
{
    if (S->next == NULL)
    {
        return TRUE;
    }
    return FALSE;
}
Status push(LiStack *S, ElemType e)
{
    LiNode *t = (LiNode *)malloc(sizeof(LiNode));
    if (t == NULL)
    { //分配内存失败
        return FALSE;
    }
    t->data = e;
    t->next = (*S)->next;
    (*S)->next = t;
    return TRUE;
}
Status pop(LiStack *S, ElemType *e)
{ // 传入参数e，将出栈的元素赋值给e
    LiNode *p = (*S)->next;
    if (p == NULL)
    {
        return FALSE;
    }
    *e = p->data;
    (*S)->next = p->next;
    free(p);
    return TRUE;
}
Status getTop(LiStack *S, ElemType *e)
{ // 在栈不为空的条件下，将头节点后继数据节点的数据域赋给e
    LiNode *p = (*S)->next;
    if (p != NULL)
    {
        *e = p->data;
        return TRUE;
    }
    return FALSE;
}

int main()
{
    LiStack s;
    ElemType e;
    initStack(&s);
    push(&s, 1);
    push(&s, 2);
    getTop(&s, &e);
    printf("%d\n", e);

    pop(&s, &e);
    getTop(&s, &e);
    printf("%d", e);
}