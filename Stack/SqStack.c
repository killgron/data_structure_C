#include "SqStack.h"

/*
栈空条件：top=-1
栈满条件：top=MaxSize-1
进栈e操作：top++; 将e放在top处
退栈操作：从top处取出元素e; top--;
*/

void initStack(SqStack *S)
{
    // S =(SqStack*)malloc(sizeof(SqStack));
    S->top = -1;
}
void destoryStack(SqStack *S)
{
    S->top = -1;
}
Bool isEmpty(SqStack S)
{
    if (S.top == -1)
    {
        return TRUE;
    }
    return FALSE;
}
Status push(SqStack *S, ElemType e)
{
    if (S->top < MAXSIZE - 1)
    {
        S->data[++S->top] = e;
        return TRUE;
    }
    return FALSE;
}

Status pop(SqStack *S, ElemType *e)
{
    if (S->top > -1)
    {
        *e = S->data[S->top--];
        return TRUE;
    }
    return FALSE;
}

Status getTop(SqStack *S, ElemType *e)
{
    if (S->top > -1)
    {
        *e = S->data[S->top];
        return TRUE;
    }
    return FALSE;
}

/*栈相关应用实现*/

//1.括号匹配
Bool bracketCheck(char str[], unsigned int len)
{
    SqStack s;
    initStack(&s);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            push(&s, str[i]);
        }
        else
        {
            if (isEmpty(s))
            {
                return FALSE;
            }
            ElemType e;
            pop(&s, &e);
            if (str[i] == '}' && e != '{')
            {
                return FALSE;
            }
            if (str[i] == ']' && e != '[')
            {
                return FALSE;
            }
            if (str[i] == ')' && e != '(')
            {
                return FALSE;
            }
        }
    }
    return isEmpty(s);
}

//表达式求值（栈实现）
/*
1.中缀表达式转换为后缀表达式
2.中缀表达式转换为前缀表达式

------------------------
中缀表达式的计算（中缀表达式转换为后缀表达式，再对后缀表达式求值）

*/
//中缀转后缀
void convertToSufExp(char exp[], int len)
{
    SqStack s;
    char *str;
    str = (char *)malloc(sizeof(char) * len);
    int index = 0;
    ElemType e;
    initStack(&s);
    for (int i = 0; i < len; i++)
    {
        switch (exp[i])
        {
        case '+':
        case '-':
            getTop(&s, &e);
            while (e != '(' && !isEmpty(s))
            {
                pop(&s, &e);

                str[index++] = e;
            }
            push(&s, exp[i]);
            break;
        case '*':
        case '/':
            //依次弹出栈中优先级高于或等于当前运算符的所有运算符,并加入后缀表达式,直到碰到 '(' 或者栈空
            getTop(&s, &e);
            while (e == '/' || e == '*')
            {
                pop(&s, &e);
                str[index++] = e;
                getTop(&s, &e);
            }
            push(&s, exp[i]);
            break;
        case '(':
            push(&s, exp[i]);
            break;
        case ')':
            getTop(&s, &e);
            while (e != '(' && !isEmpty(s))
            {
                pop(&s, &e);
                str[index++] = e;
                getTop(&s, &e);
            }
            pop(&s, &e); //去除 (
            break;
        default:
            str[index++] = exp[i];
            break;
        }
    }
    //将后续栈中元素依次放入
    while (!isEmpty(s))
    {
        pop(&s, &e);
        str[index++] = e;
    }
    for (int i = 0; i < len; i++)
    {
        exp[i] = str[i];
    }
}

int main()
{
    // SqStack s;
    // ElemType e;
    // initStack(&s);
    // push(&s, 1);
    // push(&s, 2);
    // 括号匹配测试
    // char str[6]={'{','(',')','}','(',')'};
    // if(bracketCheck(str,6)){
    //     printf("匹配成功");
    // }else{
    //      printf("匹配失败");
    // }
    // printf("+:%d,-:%d,*:%d,/:%d",'+','-','*','/');//运算符ascii +:43,-:45,*:42,/:47
    // char exp[11] = {'A', '+', 'B', '-', 'C', '*', 'D', '/', 'E', '+', 'F'};
    // convertToSufExp(exp, 11);    成功
    // char exp[13] = {'A', '+', 'B', '*','(', 'C', '-', 'D',')', '-', 'E', '/', 'F'};
    // convertToSufExp(exp, 13);    带括号,成功
    char str[28];
    int e;
    scanf("%s", str);
    int len = strlen(str);
    // printf("%d",strlen(str));
    convertToSufExp(str, 28); // 多个括号，成功
    // figureExp(str, 28, &e);
    return 0;
}
