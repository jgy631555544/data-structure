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
bool GetHead(LinkQueue Q, int &x);//获取队头元素
bool QueueEmpty(LinkQueue Q);//判空

void InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = NULL;
}

bool EnQueue(LinkQueue &Q, int x) {
    LinkNode *q = (LinkNode *) malloc(sizeof(LinkNode));
    if (q == NULL) return false;
    q->data = x;
    q->next = NULL;
    if (Q.front == NULL) {
        Q.front = Q.rear = q;
    } else {
        Q.rear->next = q;
        Q.rear = q;
    }
    return true;
}

bool DeQueue(LinkQueue &Q, int &x) {
    if (Q.front == NULL && Q.rear == NULL) return false;
    LinkNode *q = Q.front;
    x = q->data;

}