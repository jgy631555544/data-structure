//
// Created by SESA622684 on 2022/1/12.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *next, *prior;
} DNode, *DLinkList;

//函数声明
bool InitDLinkList(DLinkList &L);//初始化
bool Empty(DLinkList L);//判空
bool InsertNextElem(DNode *p, DNode *s);//指定节点的后插操作
bool DeleteNextNode(DNode *p);//删除P节点的后继节点
bool DestroyList(DLinkList &L);//销毁整个表
bool PrintNextElems(DNode *p);//从P点向后遍历
bool PrintPriorElems(DNode *p);//从P点向前遍历
bool PrintPriorElemsOverHead(DNode *p);//从P点向前遍历（跳过头节点）

bool InitDLinkList(DLinkList &L) {
    L = (DNode *) malloc(sizeof(DNode));
    if (L == NULL) {
        return false;
    }
    L->next = NULL;
    L->prior = NULL;
};

bool Empty(DLinkList L) {
    return L->next == NULL;
}

bool InsertNextElem(DNode *p, DNode *s) {
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

bool DeleteNextNode(DNode *p) {
    if (p == NULL) return false;
    DNode *node = p->next;
    p->next = node->next;
    if (node->next != NULL) return false;
    node->next->prior = p;
    free(node);
    return true;
}

bool DestoryList(DLinkList L) {
    if (L == NULL) return true;
    while (L->next != NULL) DeleteNextNode(L);
    free(L);
    return true;
}

bool PrintNextElems(DNode *p) {
    if (p == NULL) return true;
    while (p != NULL) {
        printf("节点的值为：%d", p->data);
        p = p->next;
    };
    return true;
}

bool PrintPriorElems(DNode *p) {
    if (p == NULL) return true;
    while (p != NULL) {
        printf("节点的值为：%d", p->data);
        p = p->prior;
    };
    return true;
};

bool PrintPriorElemsOverHead(DNode *p) {
    if (p == NULL) return true;
    while (p->prior != NULL) {
        printf("节点的值为：%d", p->data);
        p = p->prior;
    };
    return true;
}

int main() {

    return 0;
};