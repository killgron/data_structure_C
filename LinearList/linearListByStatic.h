#include "define.h"


#define LIST_INIT_SIZE 10
#define LIST_INCREMENT 5
#define LIST_MAX_SIZE 50

typedef int ElemType;

typedef struct 
{
    ElemType data[LIST_MAX_SIZE];
    int length;
}SqList;

//基本运算
void initList(SqList*);
void destroyList(SqList*);
Status isEmpty(SqList*);
int getLength(SqList*);
void displayList(SqList*);
ElemType getElem(SqList*,unsigned int);
int locateElem(SqList*,int);
Status insertElem(SqList*,unsigned int,ElemType);
Status deleteElem(SqList*,unsigned int);



