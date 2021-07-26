#include "define.h"


#define LIST_INIT_SIZE 10
#define LIST_INCREMENT 5

typedef int ElemType;

typedef struct 
{
    ElemType *base;
    int length;
    int max_size;
}SqList;

//基本运算

void initList(SqList*);
void destroyList(SqList*);
Status isEmpty(SqList*);
int getLength(SqList*);
void displayList(SqList*);
ElemType getElem(SqList*,int);
int locateElem(SqList*,int);
Status insertElem(SqList*,int,ElemType);
Status deleteElem(SqList*,int); 
void increaseList(SqList*);



