#include "define.h"

#define _FUNC_

#ifdef _FUNC_
typedef char ElemType;
#else
typedef int ElemType;
#endif


#define MAXSIZE 10

typedef struct 
{
    ElemType data[MAXSIZE];
    int top;
}SqStack;


void initStack(SqStack*);
void destoryStack(SqStack*);
Bool isEmpty(SqStack);
Status push(SqStack*,ElemType);
Status pop(SqStack*,ElemType *);// 传入参数e，将出栈的元素赋值给e
Status getTop(SqStack*,ElemType *);