//
// Created by SESA622684 on 2022/1/12.
//
#include <stdio.h>
#include <stdlib.h>

//����ͷ��������
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

bool InitList(LinkList &L);

bool Empty(LinkList L);

bool ListInsert(LinkList &L, int i, int e);

bool InitList(LinkList &L) {
    L = NULL;
    return true;
};

bool Empty(LinkList L) {
    return L == NULL;
};

bool ListInsert(LinkList &L, int i, int e) {
    if (i < 1) return false;
    if (i == 1) {
        LNode *node = (LNode *) malloc(sizeof(LNode));
        node->data = e;
        node->next = NULL;
        L = node;
        return true;
    }
    LNode *p;
    int index = 0;
    p = L;
    while (p!=NULL && index < i-1){
        p = p->next;
        index++;
    };
    if(p == NULL) return false;
    LNode *node = (LNode*) malloc(sizeof(LNode));
    node->data = e;
    node->next = p->next;
    p->next = node;
    return true;
}

void TestPrint(bool test, char about[]) {
    if (test)
        printf("%s�ɹ�\n", about);
    else
        printf("%sʧ��\n", about);
}

void PrintList(LinkList L) {
    //ѭ����ӡ��������
    LNode *p = L;//ɨ��ָ��
    int j = 0;
    if (p == NULL)printf("����һ���ձ�\n");
    while (p != NULL) {
        printf("LinkList[%d]=%d", j, p->data);
        p = p->next;
        j++;
    }
}

int main() {
    LinkList L;
    TestPrint(InitList(L), "��ʼ��");
    PrintList(L);
    TestPrint(ListInsert(L, 1, 2), "��λ����");
    PrintList(L);
    return 0;
};