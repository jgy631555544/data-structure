//
// Created by 金冠宇 on 2022/7/4.
//

// 顺序栈的实现

#include <stdio.h>

#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int top;
} sequenceStack;

//函数声明
void InitStack(sequenceStack &S);//初始化
bool Push(sequenceStack &S, int t);//入栈
bool Pop(sequenceStack &S, int &x);//出栈,并打印出栈顶元素
bool GetTop(sequenceStack S, int &x);//读取栈顶元素
int GetTopOther(sequenceStack S);//读取栈顶元素的第二种实现方式

void InitStack(sequenceStack &S) {
    S.top = -1;
}

bool Push(sequenceStack &S, int t) {
    if (S.top == MaxSize - 1) return false;
    S.top += 1;
    S.data[S.top] = t;
    return true;
}

bool Pop(sequenceStack &S, int &x) {
    if (S.top == -1) return false;
    x = S.data[S.top];
    S.top -= 1;
    return true;
}

bool GetTop(sequenceStack S, int &x){
    if(S.top == -1) return false;
    x = S.data[S.top];
    return true;
}

int GetTopOther(sequenceStack S) {
    if(S.top == -1) return -1;
    return S.data[S.top];
}

//打印整个栈
void PrintStack(sequenceStack S) {
    printf("从栈顶元素开始，栈如下：\n");
    while (S.top >= 0) {//注意判空的条件
        printf("S[%d]=%d\n", S.top, S.data[S.top]);
        S.top--;
    }
    printf("栈打印完毕\n");
}

void testStack() {
    printf("开始测试\n");
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
    int x;
    if (Pop(S, x)) {
        printf("出栈成功，弹出的元素为:%d\n", x);
    } else {
        printf("出栈失败了，再检出一下吧！\n");
    }
    PrintStack(S);
    int x1;
    if (GetTop(S, x1)) {
        printf("读取栈顶元素成功了，栈顶元素为：%d\n", x1);
    } else {
        printf("读取栈顶元素失败，再检查一下吧！\n");
    }
    int x4 = GetTopOther(S);
    if (x4 != -1) {
        printf("第二种读取栈顶元素的方式成功了，栈顶元素为：%d\n", x4);
    } else {
        printf("第二种读取栈顶元素的方式失败了\n");
    }

    printf("测试完毕了！\n");
}
/**测试模块**/

int main() {
    printf("Hello, SqStack!");
    testStack();
    return 0;
}