#include "linearListByDynamic.h"

void initList(SqList *L)
{
    L->base = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    L->length = 0;
    L->max_size = LIST_INIT_SIZE;
}

void initListByList(SqList *L, int *data, int len)
{
    L->base = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    L->length = 0;
    L->max_size = LIST_INIT_SIZE;
    if (len <= L->max_size)
    {
        for (int i = 0; i < len; i++)
        {
            L->base[i] = data[i];
        }
    }
    L->length = len;
}

void destroyList(SqList *L)
{
    free(L->base);
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
        printf("%d\t", L->base[i]);
    }
}

//获取的下标为index的值，而不是第index个值
ElemType getElem(SqList *L, int index)
{
    if (index < L->length)
        return L->base[index];
    else
        return INFEASIBLE;
}

int locateElem(SqList *L, int e)
{
    int result = INFEASIBLE;
    for (int i = 0; i < L->length; i++)
    {
        if (L->base[i] == e)
        {
            result = i;
        }
    }
    return result;
}

//增加序号为index的
Status insertElem(SqList *L, int index, ElemType e)
{
    Status result = INFEASIBLE;
    if (index < L->length && L->length < L->max_size && index > 0)
    {
        int j;
        for (j = L->length - 1; j >= index; j--)
        {
            L->base[j + 1] = L->base[j];
        }
        L->base[index] = e;
        L->length++;
        result = OK;
    }
    return result;
}
Status deleteElem(SqList *L, int index)
{
    Status result = INFEASIBLE;
    if (index < L->length)
    {
        for (int j = index; j < L->length - 1; j++)
        {
            L->base[j] = L->base[j + 1];
        }
        result = OK;
        L->length--;
    }
    return result;
}

void increaseList(SqList *L)
{
    ElemType *p = L->base;
    L->base = (ElemType *)malloc(sizeof(ElemType) * (L->max_size + LIST_INCREMENT));
    for (int i = 0; i < L->length; i++)
    {
        L->base[i] = p[i];
    }
    L->max_size = L->max_size + LIST_INCREMENT;
    free(p);
}

//算法实现：
/*
* 从顺序表中删除其值在给定值s和t之间（s<t)的所有元素,如果s和t不合理或者顺序表为空,则显示错误信息,并退出运行.
*/
void delVal(SqList *L, int s, int t)
{
    int k = 0;
    for (int i = 0; i < L->length; i++)
    {
        if (L->base[i] >= s && L->base[i] <= t)
        {
            k++;
        }
        else
        {
            L->base[i - k] = L->base[i];
        }
    }
    L->length -= k;
}

//从有序顺序表中删除所有其值重复的元素,使表中所有元素的值均不同
void delSameVal(SqList *L)
{
}

//
void reverse(SqList *L, int h, int r)
{
    while (h < r)
    {
        ElemType temp = L->base[h];
        L->base[h] = L->base[r];
        L->base[r] = temp;
        h++;
        r--;
    }
}

int main()
{
    SqList L;
    int data[10] = {
        0,
        1,
        2,
        7,
        8,
        9,
        3,
        4,
        5,
        6,
    };
    initListByList(&L, data, 10);
    displayList(&L);
    printf("\n");
    reverse(&L, 0, L.length - 1);
    reverse(&L, 0, 3);
    reverse(&L, 4, L.length - 1);
    // delVal(&L, 2, 6);
    // printf("\n");
    displayList(&L);
    // increaseList(&L);
    // if (insertElem(&L, 2, 11) == OK)
    //     printf("%d\n", getLength(&L));
    //  displayList(&L);
    // if (deleteElem(&L, 2) == OK)
    //     printf("\n%d\n", getLength(&L));

    // displayList(&L);

    return 0;
}