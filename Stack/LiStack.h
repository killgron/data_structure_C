#include "define.h"

typedef int ElemType;

#define MAXSIZE 10

typedef struct linkNode
{
    ElemType data;
    struct linkNode* next;
}LiNode,*LiStack;


void initStack(LiStack*);
void destoryStack(LiStack*);
Bool isEmpty(LiStack);
Status push(LiStack*,ElemType);
Status pop(LiStack*,ElemType *);// 传入参数e，将出栈的元素赋值给e
Status getTop(LiStack*,ElemType *);// 在栈不为空的条件下，将头节点后继数据节点的数据域赋给e