//
// Created by SESA622684 on 2022/1/12.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *Linklist;

bool InitList(Linklist &L);

bool Empty(Linklist L);

bool ListInsert(Linklist &L, int i, int e);

bool InitList(Linklist &L) {
    L = NULL;
    return true;
};

bool Empty(Linklist L) {
    return L == NULL;
};

bool ListInsert(Linklist &L, int i, int e) {
    if (i < 1) return false;
    if (i == 1) {
        LNode *s = (LNode *) malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;
        return true;
    };
    LNode *point;
    int j = 0;

    return true;
}

int main() {
    Linklist L;
    InitList(L);
    return 0;
};