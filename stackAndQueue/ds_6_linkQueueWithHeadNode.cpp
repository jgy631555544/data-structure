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

void InitQueue(LinkQueue &Q);//��ʼ��
bool EnQueue(LinkQueue &Q, int x);//��Ӳ���
bool DeQueue(LinkQueue &Q, int &x);//����
bool GetHead(LinkQueue Q, int &x);//��ȡͷԪ��
bool QueueEmpty(LinkQueue Q);//�п�

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

/**����ģ��**/
void PrintQueue(LinkQueue Q) {
    printf("��ʼ��ӡ����\n");
    int i = 0;
    while (Q.front != Q.rear) {
        Q.front = Q.front->next;
        printf("Q[%d]=%d\n", i++, Q.front->data);
    }
    printf("��ӡ��ϣ�\n");
}

//���Ժ���
void TestLinkQueue() {
    printf("��ʼ���ԣ�\n");
    LinkQueue Q;
    InitQueue(Q);
    if (EnQueue(Q, 1)) {
        printf("��ӳɹ�����\n");
    } else {
        printf("���ʧ����\n");
    }
    if (EnQueue(Q, 2)) {
        printf("����ֳɹ�����\n");
    } else {
        printf("�����ʧ����\n");
    }
    PrintQueue(Q);
    int x;
    if (DeQueue(Q, x)) {
        printf("���ӳɹ���������Ԫ��Ϊ:%d\n", x);
    } else {
        printf("����ʧ���ˣ��ټ��һ�°ɣ�\n");
    }
    if (GetHead(Q, x)) {
        printf("��ȡ��ͷ�ɹ���,��ͷԪ��Ϊ��%d\n", x);
    } else {
        printf("��ȡ��ͷԪ��ʧ�ܣ�\n");
    }
    if (DeQueue(Q, x)) {
        printf("���ӳɹ���������Ԫ��Ϊ:%d\n", x);
    } else {
        printf("����ʧ���ˣ��ټ��һ�°ɣ�\n");
    }
    if (QueueEmpty(Q)) {
        printf("�ӿ���\n");
    } else {
        printf("�ӷǿ�\n");
    }

    printf("���Խ���!\n");
}

/**����ģ��**/

int main() {
    TestLinkQueue();
    return 0;
}