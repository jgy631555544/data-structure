//
// Created by jgy66 on 2022/1/15.
//
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

//函数声明
bool InitList(LinkList &L);     //初始化
bool Empty(LinkList L);         //盘空
bool ListInsert(LinkList &L, int i, int e);//按位插入
bool InsertNextNode(LNode *p, int e);//指定节点的后插操作
bool InsertPriorNode(LNode *p, int e);//指定节点的前插操作————先完成后插，再交换数据以实现前插
bool ListDelete(LinkList &L, int i, int &e);//按指定位序删除节点并返回其值
bool DeleteNode(LNode *p);//删除指定节点

bool InitList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));
    if (L == NULL) {
        return false;
    }
    L->next = NULL;
    return true;
}

bool Empty(LinkList L) {
    return L->next == NULL;
}

bool ListInsert(LinkList &L, int i, int e) {
    if (i < 0) return false;
    LNode *p;
    int index = 0;
    p = L;
    while (p != NULL && index < i - 1) {
        p = p->next;
        index++;
    };
    if (p == NULL) return false;
    LNode *node = (LNode *) malloc(sizeof(LNode));
    node->next = p->next;
    node->data = e;
    p->next = node;
    return true;
}

bool InsertNextNode(LNode *p, int e) {
    if (p == NULL)return false;
    LNode *node = (LNode *) malloc(sizeof(LNode));
    if (node == NULL)return false;
    node->next = p->next;
    node->data = e;
    p->next = node;
    return true;
}

bool InsertPriorNode(LNode *p, int e) {
    if (p == NULL) return false;
    LNode *node = (LNode *) malloc(sizeof(LNode));
    if (node == NULL)return false;
    node->next = p->next;
    p->next = node;
    node->data = p->data;
    p->data = e;
    return true;
};

bool ListDelete(LinkList &L, int i, int &e) {
    if (i < 1)return false;
    int index = 0;
    LNode *node = L;
    while (node->next != NULL && index < i - 1) {
        node = node->next;
        index++;
    }
    LNode *deleteNode = node->next;
    e = deleteNode->data;
    node->next = deleteNode->next;
    free(deleteNode);
    return true;
}

bool DeleteNode(LNode *p){
    if(p == NULL) return false;
    LNode *node = p->next;
    p->data = node->data;
    p->next = node->next;
    free(node);
    return true;
};


int main() {
    return 0;
};