//
// Created by SESA622684 on 2022/1/12.
//

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


int main() {

    return 0;
};