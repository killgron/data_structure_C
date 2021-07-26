#include "define.h"


#define LIST_INIT_SIZE 10
#define LIST_INCREMENT 5

typedef int ElemType;

typedef struct Node
{
   ElemType value;
   struct Node* next;
}LNode,*LinkList;

//基本运算

void initList(LinkList*);
//头插法建表
void createListF(LinkList*,ElemType*,unsigned int);
//尾插法建表
void createListR(LinkList*,ElemType*,unsigned int);

void destroyList(LinkList*);
Status isEmpty(LinkList*);
int getLength(LinkList*);
void displayList(LinkList*);
ElemType getElem(LinkList*,unsigned int);
int locateElem(LinkList*,ElemType);
Status insertElem(LinkList*,unsigned int,ElemType);
Status deleteElem(LinkList*,unsigned int); 
// void increaseList(LinkList*);



