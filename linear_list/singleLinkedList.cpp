//
// Created by SESA622684 on 2022/1/12.
//
#include <stdio.h>

typedef struct {
    int data;
    struct LinkNode *next;
} *Linklist;

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

int main() {
    Linklist L;
    InitList(L);
    return 0;
};