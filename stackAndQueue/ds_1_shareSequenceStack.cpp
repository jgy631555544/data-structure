//
// Created by 金冠宇 on 2022/7/4.
//

#include <stdio.h>

#define MaxSize 20
typedef struct {
    int data[MaxSize];
    int top0;
    int top1;
} shareSequenceStack;

void InitStack(shareSequenceStack &S);//初始化
bool Push0(shareSequenceStack &S, int t);//入栈0
bool Push1(shareSequenceStack &S, int t);//入栈1
bool Pop0(shareSequenceStack &S, int &x);//出栈,并打印出栈顶元素
bool Pop1(shareSequenceStack &S, int &x);//出栈1
bool GetTop0(shareSequenceStack S, int &x);//读取栈顶元素，栈0
bool GetTop1(shareSequenceStack S, int &x);//栈1

void InitStack(shareSequenceStack &S) {
    S.top0 = -1;
    S.top1 = MaxSize;
}

bool Push0(shareSequenceStack &S, int t) {
    if (S.top0 + 1 == S.top1) return false;
    S.top0 += 1;
    S.data[S.top0] = t;
    return true;
}

bool Push1(shareSequenceStack &S, int t) {
    if (S.top0 == S.top1 - 1) return false;
    S.top1 -= 1;
    S.data[S.top1] = t;
    return true;
}

bool Pop0(shareSequenceStack &S, int &x) {
    if (S.top0 == -1)return false;
    x = S.data[S.top0];
    S.top0 -= 1;
    return true;
}

bool Pop1(shareSequenceStack &S, int &x) {
    if (S.top1 == MaxSize)return false;
    x = S.data[S.top1];
    S.top1 += 1;
    return true;
}

bool GetTop0(shareSequenceStack S, int &x) {
    if (S.top0 == -1) return false;
    x = S.data[S.top0];
    return true;
}

bool GetTop1(shareSequenceStack S, int &x) {
    if (S.top1 == MaxSize) return false;
    x = S.data[S.top1];
    return true;
}

/**测试模块**/
//打印整个栈,栈0
void PrintStack0(shareSequenceStack S) {
    printf("从栈顶元素开始，栈如下：\n");
    while (S.top0 > -1) {//注意判空的条件
        printf("S[%d]=%d\n", S.top0, S.data[S.top0--]);
    }
    printf("栈打印完毕\n");
}

//打印整个栈
void PrintStack1(shareSequenceStack S) {
    printf("从栈顶元素开始，栈如下：\n");
    while (S.top1 < MaxSize) {//注意判空的条件
        printf("S[%d]=%d\n", S.top1, S.data[S.top1++]);
    }
    printf("栈打印完毕\n");
}

void testshareSequenceStack() {
    printf("开始测试\n");
    shareSequenceStack S;
    InitStack(S);
    printf("测试第一个栈\n");
    if (Push0(S, 1)) {
        printf("入栈成功啦！\n");
    } else {
        printf("入栈失败了\n");
    }
    if (Push0(S, 2)) {
        printf("入栈又成功啦！\n");
    } else {
        printf("入栈又失败了\n");
    }
    PrintStack0(S);
    int x;
    if (Pop0(S, x)) {
        printf("出栈成功，弹出的元素为:%d\n", x);
    } else {
        printf("出栈失败了，再检出一下吧！\n");
    }
    PrintStack0(S);
    int x1;
    if (GetTop0(S, x1)) {
        printf("读取栈顶元素成功了，栈顶元素为：%d\n", x1);
    } else {
        printf("读取栈顶元素失败，再检查一下吧！\n");
    }


    printf("测试第二个栈\n");
    if (Push1(S, 10)) {
        printf("入栈成功啦！\n");
    } else {
        printf("入栈失败了\n");
    }
    if (Push1(S, 9)) {
        printf("入栈又成功啦！\n");
    } else {
        printf("入栈又失败了\n");
    }
    PrintStack1(S);
    int x3;
    if (Pop1(S, x3)) {
        printf("出栈成功，弹出的元素为:%d\n", x3);
    } else {
        printf("出栈失败了，再检出一下吧！\n");
    }
    PrintStack1(S);
    int x4;
    if (GetTop1(S, x4)) {
        printf("读取栈顶元素成功了，栈顶元素为：%d\n", x4);
    } else {
        printf("读取栈顶元素失败，再检查一下吧！\n");
    }


    printf("测试完毕了！\n");
}

/**测试模块**/

int main() {
    printf("Hello, shareSequenceStack!");
    testshareSequenceStack();
    return 0;
}
