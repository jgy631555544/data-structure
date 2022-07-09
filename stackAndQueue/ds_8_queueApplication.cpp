//
// Created by SESA622684 on 2022/7/8.
//

// 栈的应用-括号问题
#include <stdio.h>

#define MaxSize 10
typedef struct {
    int data[MaxSize];
    int top;
} sequenceStack;

void InitStack(sequenceStack &S);

bool Push(sequenceStack &S, char t);

bool Pop(sequenceStack &S, char &x);

bool StackEmpty(sequenceStack S);

void InitStack(sequenceStack &S) {
    S.top = -1;
}

bool Push(sequenceStack &S, char t) {
    if (S.top == MaxSize - 1)return false;
    S.top++;
    S.data[S.top] = t;
    return true;
}

bool Pop(sequenceStack &S, char &x) {
    if (S.top == -1) {
        return false;
    }
    x = S.data[S.top];
    S.top--;
    return true;
}

bool StackEmpty(sequenceStack S) {
    return S.top == -1;
}

bool bracketCheck(char *str, int length) {
    sequenceStack S;
    InitStack(S);
    for (int i = 0; i < length; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            Push(S, str[i]);
        } else {
            if (StackEmpty(S)) {
                return false;
            }
            char ele;
            Pop(S, ele);
            if (ele == '(' && str[i] != ')' || ele == '[' && str[i] != ']' || ele == '{' && str[i] != '}') {
                return false;
            }
        }
    }
    return StackEmpty(S);
}

/**测试模块**/
//打印整个栈
void PrintStack(sequenceStack S) {
    printf("从栈顶元素开始，栈如下：\n");
    while (S.top >= 0) {//注意判空的条件
        printf("S[%d]=%d\n", S.top, S.data[S.top--]);
    }
    printf("栈打印完毕\n");
}

void TestQueueApplication(){
    printf("开始测试\n");

    /**基础操作测试**/

    sequenceStack S;
    printf("测试第一种初始化方式\n");
    InitStack(S);
    if (Push(S, 1)) {
        printf("入栈成功啦！\n");
    } else {
        printf("入栈失败了\n");
    }
    if (Push(S, 2)) {
        printf("入栈又成功啦！\n");
    } else {
        printf("入栈又失败了\n");
    }
    PrintStack(S);
    char x;
    if (Pop(S, x)) {
        printf("出栈成功，弹出的元素为:%d\n", x);
    } else {
        printf("出栈失败了，再检出一下吧！\n");
    }

    /**测试括号问题部分源码**/
    if(bracketCheck("[({})]",6))
        printf("字符串括号匹配成功\n");
    else
        printf("字符串括号匹配失败\n");
    if(bracketCheck("[({})",5))
        printf("字符串括号匹配成功\n");
    else
        printf("字符串括号匹配失败\n");

    printf("测试完毕了！\n");
}
/**测试模块**/

int main(){
    TestQueueApplication();
    return 0;
}