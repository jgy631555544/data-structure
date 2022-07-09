//
// Created by SESA622684 on 2022/7/8.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct {
    LinkNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue &Q);//初始化
bool EnQueue(LinkQueue &Q, int x);//入队操作
bool DeQueue(LinkQueue &Q, int &x);//出队
bool GetHead(LinkQueue Q, int &x);//获取头元素
bool QueueEmpty(LinkQueue Q);//判空

void InitQueue(LinkQueue &Q) {
    Q.front = (LinkNode *) malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

bool EnQueue(LinkQueue &Q, int x) {
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
    if (s == NULL) return false;
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
    return true;
}

bool DeQueue(LinkQueue &Q, int &x) {
    if (Q.front == Q.rear) return false;
    x = Q.front->data;
    LinkNode *p = Q.front->next;
    Q.front->next = p->next;
    if (Q.rear == p) Q.rear = Q.front;
    free(p);
    return true;
}

bool GetHead(LinkQueue Q, int &x) {
    if (Q.front == Q.rear) return false;
    x = Q.front->next->data;
    return true;
}

bool QueueEmpty(LinkQueue Q) {
    return Q.front == Q.rear ? true : false;
}

/**测试模块**/
void PrintQueue(LinkQueue Q) {
    printf("开始打印队列\n");
    int i = 0;
    while (Q.front != Q.rear) {
        Q.front = Q.front->next;
        printf("Q[%d]=%d\n", i++, Q.front->data);
    }
    printf("打印完毕！\n");
}

//测试函数
void TestLinkQueue() {
    printf("开始测试！\n");
    LinkQueue Q;
    InitQueue(Q);
    if (EnQueue(Q, 1)) {
        printf("入队成功啦！\n");
    } else {
        printf("入队失败了\n");
    }
    if (EnQueue(Q, 2)) {
        printf("入队又成功啦！\n");
    } else {
        printf("入队又失败了\n");
    }
    PrintQueue(Q);
    int x;
    if (DeQueue(Q, x)) {
        printf("出队成功，弹出的元素为:%d\n", x);
    } else {
        printf("出队失败了，再检出一下吧！\n");
    }
    if (GetHead(Q, x)) {
        printf("获取队头成功！,队头元素为：%d\n", x);
    } else {
        printf("获取队头元素失败！\n");
    }
    if (DeQueue(Q, x)) {
        printf("出队成功，弹出的元素为:%d\n", x);
    } else {
        printf("出队失败了，再检出一下吧！\n");
    }
    if (QueueEmpty(Q)) {
        printf("队空啦\n");
    } else {
        printf("队非空\n");
    }

    printf("测试结束!\n");
}

/**测试模块**/

int main() {
    TestLinkQueue();
    return 0;
}