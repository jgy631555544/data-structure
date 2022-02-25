//
// Created by SESA622684 on 2022/1/12.
//

#include <stdlib.h>

typedef struct CNode {
    int data;
    struct CNode *next;
} CNode, *CLinkList;


bool InitCLinkList(CLinkList &L);//初始化
bool IsTail(CLinkList L, CNode *p);//判断P是不是表尾指针

bool InitCLinkList(CLinkList &L) {
    L = (CNode *) malloc(sizeof(CNode));
    if (L == NULL) return false;
    L->next = L;
    return true;
}

bool IsTail(CLinkList L, CNode *p) {
    return p->next == L;
}


int main() {
    return 0;
};