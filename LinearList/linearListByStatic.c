#include "linearListByStatic.h"

void initList(SqList *L)
{
    L->length = 0;
}

void initListByList(SqList *L, int *data, int len)
{

    for (int i = 0; i < len && i < LIST_MAX_SIZE; i++)
    {
        L->data[i] = data[i];
    }
    L->length = len;
}

void destroyList(SqList *L)
{
    L->length = 0;
}

Status isEmpty(SqList *L)
{
    if (L->length == 0)
        return TRUE;
    else
        return FALSE;
}

int getLength(SqList *L)
{
    return L->length;
}
void displayList(SqList *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%d", L->data[i]);
    }
}

//获取的下标为index的值，而不是第index个值
ElemType getElem(SqList *L, unsigned int index)
{
    if (index < L->length)
    {
        printf("%d", L->data[index]);
    }
}

int locateElem(SqList *L, int e)
{
    int i = -1;
    for (int j = 0; j < L->length; j++)
    {
        if (L->data[j] == e)
        {
            i = j;
        }
    }
    return i;
}
Status insertElem(SqList *L, unsigned int index, ElemType e)
{
    Status result = INFEASIBLE;
    int j = 0;
    if (index < L->length && L->length < LIST_MAX_SIZE)
    {
        for (int j = L->length - 1; j >= index; j--)
        {
            L->data[j + 1] = L->data[j];
        }
        L->data[j] = e;
        L->length++;
        result = OK;
    }
    return result;
}

Status deleteElem(SqList *L, unsigned int index)
{
    Status result = INFEASIBLE;
    if (index < L->length)
    {
        for (int j = index - 1; j < L->length; j++)
        {
            L->data[j] = L->data[j + 1];
        }
        L->length--;
        result = OK;
    }
    return result;
}

int main()
{
    SqList L;
    initList(&L);
    for (int i = 0; i < L.length; i++)
    {
        printf("%d\n", L.length);
        printf("%d\t", L.data[i]);
    }

    return 0;
}