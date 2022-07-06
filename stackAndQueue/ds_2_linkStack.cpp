//
// Created by SESA622684 on 2022/7/5.
//

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct LinkNode {
    int data;
    LinkNode *next;
} *LinkStack;

bool InitStack(LinkStack &LS);//初始化
bool Push(LinkStack &LS, int t);//入栈 参考头插法建立单链表
bool Pop(LinkStack &LS, int &x);//出栈,并打印出栈顶元素
bool GetTop(LinkStack LS, int &x);//读取栈顶元素，栈

bool InitStack(LinkStack &LS) {
    LS = (LinkNode *) malloc(sizeof(LinkNode));
    if (LS == NULL) return false;
    LS->next = NULL;
    return true;
}

bool Push(LinkStack &LS, int t) {
    LinkStack node = (LinkStack) malloc(sizeof(LinkNode));
    if (node == NULL) return false;
    node->data = t;
    node->next = LS->next;
    LS->next = node;
    return true;
}

bool Pop(LinkStack &LS, int &x) {
    if (LS->next == NULL) return false;
    LinkNode *q;
    q = LS->next;
    LS->next = q->next;
    x = q->data;
    free(q);
    return true;
}

bool GetTop(LinkStack LS, int &x){
    if(LS->next == NULL) return false;
    x = LS->next->data;
    return true;
}

/**测试模块**/
//打印整个栈,栈
void PrintStack(LinkStack LS) {
    printf("从栈顶元素开始，栈如下：\n");
    int i = 0;
    int x;
    LinkNode *p = LS->next;
    while (p != NULL) {//注意判空的条件
        printf("S[%d]=%d\n", i, p->data);
        p = p->next;
        i++;
    }
    printf("栈打印完毕\n");
}

void testLinkStack() {
    printf("开始测试\n");
    LinkStack S;
    InitStack(S);
    printf("测试第一个栈\n");
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

    if (Pop(S, x)) {
        printf("出栈成功，弹出的元素为:%d\n", x);
    } else {
        printf("出栈失败了，再检出一下吧！\n");
    }
    if (Pop(S, x)) {
        printf("出栈成功，弹出的元素为:%d\n", x);
    } else {
        printf("出栈失败了，再检出一下吧！\n");
    }

    printf("测试完毕了！\n");
}
/**测试模块**/

int main() {
    printf("Hello, LinkNode!");
    testLinkStack();
    return 0;
}