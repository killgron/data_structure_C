#include "define.h"


#define LIST_INIT_SIZE 10
#define LIST_INCREMENT 5

typedef int ElemType;

typedef struct Node
{
   ElemType value;
   struct Node* pre;
   struct Node* next;
}DNode,*DLinkList;

//基本运算

void initList(DLinkList*);
//头插法建表
void createListF(DLinkList*,ElemType*,unsigned int);
//尾插法建表
void createListR(DLinkList*,ElemType*,unsigned int);

void destroyList(DLinkList*);
Status isEmpty(DLinkList*);
int getLength(DLinkList*);
void displayList(DLinkList*);
ElemType getElem(DLinkList*,unsigned int);
int locateElem(DLinkList*,ElemType);
Status insertElem(DLinkList*,unsigned int,ElemType);
Status deleteElem(DLinkList*,unsigned int); 
// void increaseList(DLinkList*);



