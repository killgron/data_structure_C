#include "DLinkList.h"

void initList(DLinkList *L)
{
    *L = (DNode *)malloc(sizeof(DNode));
    (*L)->pre = NULL;
    (*L)->next = NULL;
}
//头插法建表
void createListF(DLinkList *L, ElemType *data, unsigned int len)
{
    //建立头节点
    *L = (DNode *)malloc(sizeof(DNode));
    (*L)->pre = NULL;
    (*L)->next = NULL;
    for (int i = 0; i < len; i++)
    {
        DNode *temp = (DNode *)malloc(sizeof(DNode));
        temp->value = data[i];
        //修改 temp->next 指针,使 temp->next 指向 原先 l->next 指向的节点 (将temp插入到头节点之后)
        temp->next = (*L)->next;
        //若原先 l->next 指向的节点不为空,修改该节点,使其指向temp(若l存在数据节点,修改前驱指针)
        if ((*L)->next != NULL)
        {
            (*L)->next->pre = temp;
        }
        //修改l->next 指针,将 l->next 指向 temp
        (*L)->next = temp;
        temp->pre = (*L);
    }
}
//尾插法建表
void createListR(DLinkList *L, ElemType *data, unsigned int len)
{
    //建立头节点
    *L = (DNode *)malloc(sizeof(DNode));
    (*L)->pre = NULL;
    (*L)->next = NULL;
    DNode *p = *L;
    for (int i = 0; i < len; i++)
    {
        DNode *temp = (DNode *)malloc(sizeof(DNode));
        temp->value = data[i];
        p->next = temp;
        temp->pre = p;
        temp->next = NULL;
        p = p->next;
    }
}

// void destroyList(DLinkList *);
// Status isEmpty(DLinkList *);
// int getLength(DLinkList *);
void displayList(DLinkList *L)
{
    DNode *p = (*L)->next;
    while (p != NULL)
    {
        printf("%d\t", p->value);
        p = p->next;
    }
}
// ElemType getElem(DLinkList *, unsigned int);
// int locateElem(DLinkList *, ElemType);

//在第 index位置插入 值为e 的节点，本方法思路，在index-1之后插入
Status insertElem(DLinkList *L, unsigned int index, ElemType e)
{
    DNode *p = (*L);
    int i = 1;
    while (i < index - 1 && p != NULL)
    {
        i++;
        p = p->next;
    }
    if (p == NULL)
    {
        return FALSE;
    }
    else
    {
        DNode *temp = (DNode *)malloc(sizeof(DNode));
        temp->value = e;

        temp->next = p->next;
        if (p->next != NULL)
            p->next->pre = temp;
        temp->pre = p;
        p->next = temp;
        return TRUE;
    }
}

Status deleteElem(DLinkList *L, unsigned int index){
    DNode *p = (*L)->next;
    int i = 1;
     while (i < index && p != NULL)
    {
        i++;
        p = p->next;
    }
    if (p == NULL)
    {
        return FALSE;
    }else{
        if(p->next!=NULL)
            p->next->pre=p->pre;
        p->pre->next = p->next;
        free(p);
        return TRUE;
    }
}

/*
* 算法设计
*/
/*1. 有一个带头节点的双链表L，设计一个算法将其所有元素逆置，即第1个元素变为最后一个元素，第2个元素变为倒数
第2个元素，…，最后一个元素变为第1个元素
*/
Status reverse(DLinkList* L){
    //头插法
    DNode* p=(*L)->next;
    (*L)->next = NULL;
    while (p!=NULL)
    {
        DNode* q= p->next;
        p->next = (*L)->next;
        if((*L)->next!=NULL){
            (*L)->next->pre=p;
        }
        p->pre = (*L);
        (*L)->next = p;
        p=q;
    }
    

}

int main()
{
    DLinkList l1, l2;
    ElemType data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // createListF(&l1, data, 10);
    createListR(&l2, data, 10);
    displayList(&l2);
    printf("\n");
    // deleteElem(&l2,1);
    // displayList(&l2);
    // printf("\n");
    // insertElem(&l2,1,1);
    reverse(&l2);
    displayList(&l2);

    // displayList(&l2);

    return 0;
}