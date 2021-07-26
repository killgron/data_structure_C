#include "linkList.h"

/*
* 以带头结点的单链表为默认情况，请注意与不带头节点单链表代码的区别
*/

void initList(LinkList *L)
{
    *L = (LNode *)malloc(sizeof(LNode));
    (*L)->next = NULL;
}

void createListF(LinkList *L, ElemType *data, unsigned int length)
{
    *L = (LNode *)malloc(sizeof(LNode));
    (*L)->next = NULL;
    for (int i = 0; i < length; i++)
    {
        LNode *p = (LNode *)malloc(sizeof(LNode));
        p->value = data[i];
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

void createListR(LinkList *L, ElemType *data, unsigned int length)
{
    *L = (LNode *)malloc(sizeof(LNode));
    (*L)->next = NULL;
    LNode *r = NULL;
    r = *L;
    for (int i = 0; i < length; i++)
    {
        LNode *p = (LNode *)malloc(sizeof(LNode));
        p->value = data[i];
        r->next = p;
        p->next = NULL;
        r = r->next; //r(尾指针)向后移动
    }
}

void destoryList(LinkList *L)
{
    LNode *pre = *L, *p = (*L)->next;
    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

Status isEmpty(LinkList *L)
{
    if ((*L)->next != NULL)
        return FALSE;
    else
        return TRUE;
}

int getLength(LinkList *L)
{
    int len = 0;
    LNode *p = (*L)->next;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

ElemType getElem(LinkList *L, unsigned int index)
{
    int c = 0;
    LNode *p = *L;
    while (c < index && p != NULL)
    {
        c++;
        p = p->next;
    }
    return p->value;
}

int locateElem(LinkList *L, ElemType e)
{
    int r = 0;
    LNode *p = (*L)->next;
    while (p != NULL)
    {
        if (p->value == e)
        {
            break;
        }
        r++;
        p = p->next;
    }
    return r + 1;
}

Status insertElem(LinkList *L, unsigned int index, ElemType e)
{
    Status s = ERROR;
    LNode *p = *L;
    int i = 0;
    /*
    * 两种思路
    * 1.定位到index位置,在该位置采取头插法
    * 2.定位到index-1位置,在该位置采用尾插法
    * 本方法使用第二种
    */
    while (i < index - 1 && p != NULL)
    {
        i++;
        p = p->next;
    }
    if (p != NULL)
    {
        LNode *t = (LNode *)malloc(sizeof(LNode));
        t->value = e;
        t->next = p->next;
        p->next = t;
        s = TRUE;
    }
    return s;
}
Status deleteElem(LinkList *L, unsigned int index)
{
    Status s = ERROR;
    LNode *p = *L;
    int i = 0;
    while (i < index - 1 && p != NULL)
    {
        i++;
        p = p->next;
    }
    if (p != NULL)
    {
        LNode *r = p->next;
        p->next = r->next;
        free(r);
        s = TRUE;
    }
    return s;
}

void displayList(LinkList *L)
{
    LNode *p = (*L)->next;
    while (p != NULL)
    {
        printf("%d\t", p->value);
        p = p->next;
    }
}

int main()
{
    LinkList l;
    int data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // initList(&l);
    // createListF(&l);
    createListR(&l, data, 10);
    displayList(&l);
    printf("\n%d\n", getLength(&l));
    printf("%d", getElem(&l, 2));
    return 0;
}
