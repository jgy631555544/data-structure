//
// Created by 金冠宇 on 2022/2/25.
//
#include <stdlib.h>
#include <stdio.h>

typedef struct CDNode {
    int data;
    struct CDNode *next, *prior;
} CDNode, *CDLinkList;

bool InitRDLinkList(CDLinkList &CDL);//初始化
bool iTail(CDLinkList CDL, CDNode *p);//判断节点p是不是循环双链表的表尾节点
bool InsertNextDNode(CDNode *p, CDNode *s);//在p节点之后插入s节点
bool DeleteNextDNode(CDLinkList &CDL, CDNode *p);//删除操作

bool InitRDLinkList(CDLinkList &CDL) {
    CDL = (CDNode *) malloc(sizeof(CDL));
    if (CDL == NULL) return true;
    CDL->next = CDL;
    CDL->prior = CDL;
    return true;
};

bool iTail(CDLinkList CDL, CDNode *p) {
    return p->next == CDL;
}

bool InsertNextDNode(CDNode *p, CDNode *s) {
    s->next = p->next;
    s->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

bool PrintNextElems(CDLinkList L, CDNode *p) {
    if (p == NULL) return true;
    p = p->next;
    while (p != L) {
        printf("节点的值为：%d\n", p->data);
        p = p->next;
    };
    return true;
}

bool DeleteNextDNode(CDNode *p) {
    CDNode *node = p->next;
    p->next = node->next;
    node->next->prior = p;
    free(node);
    return true;
}

int test() {
    CDLinkList CDL;
    InitRDLinkList(CDL);
    CDNode *node1 = (CDNode *) malloc(sizeof(CDNode));
    node1->data = 8;
    node1->next = NULL;
    node1->prior = NULL;
    CDNode *node2 = (CDNode *) malloc(sizeof(CDNode));
    node2->data = 9;
    node2->next = NULL;
    node2->prior = NULL;
    CDNode *node3 = (CDNode *) malloc(sizeof(CDNode));
    node3->data = 10;
    node3->next = NULL;
    node3->prior = NULL;
    InsertNextDNode(CDL, node1);
    InsertNextDNode(node1, node3);
    InsertNextDNode(node3, node2);
    PrintNextElems(CDL, CDL);
    DeleteNextDNode(CDL);
    return 0;
}

int main() {
    test();
    return 0;
};