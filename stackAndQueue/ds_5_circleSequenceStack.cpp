//
// Created by ����� on 2022/7/6.
//
#include <stdio.h>

#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int front, rear;
    int tag;
} circleSequenceStrack;

void InitQueue(circleSequenceStrack &Q);//��ʼ��
bool QueueEmpty(circleSequenceStrack Q);//�п�
bool EnQueue(circleSequenceStrack &Q, int t);//��Ӳ���
bool DeQueue(circleSequenceStrack &Q, int &x);//���Ӳ���
bool GetHead(circleSequenceStrack Q, int &x);//��ȡ��ͷԪ��,��x����

void InitQueue(circleSequenceStrack &Q) {
    Q.front = Q.rear = 0;
    Q.tag = 0;
}

bool QueueEmpty(circleSequenceStrack Q) {
    if (Q.front == Q.rear && Q.tag == 0) return false;
    return true;
}

bool EnQueue(circleSequenceStrack &Q, int t) {
    if (Q.front == Q.rear && Q.tag == 1) return false;
    Q.data[Q.rear] = t;
    Q.rear = (Q.rear + 1) % MaxSize;
    Q.tag = 1;
    return true;
}

bool DeQueue(circleSequenceStrack &Q, int &x) {
    if (Q.front == Q.rear && Q.tag == 0) return false;
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;
    Q.tag==0;
    return true;
}

bool GetHead(circleSequenceStrack Q, int &x) {
    if (Q.front == Q.rear && Q.tag == 0) return false;
    x = Q.data[Q.front];
    return true;
}

/**����ģ��**/
//��ӡ��������
void PrintQueue(circleSequenceStrack Q){
    printf("��ʼ��ӡ����\n");
    while(Q.front!=Q.rear){
        printf("Q[%d]=%d\n",Q.front,Q.data[Q.front]);
        Q.front=(Q.front+1)%MaxSize;
    }
    printf("��ӡ��ϣ�\n");
}

//����
void TestQueue(){
    printf("��ʼ���ԣ�\n");
    circleSequenceStrack Q;
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

    printf("�������ԣ�\n");
}
/**����ģ��**/

int main(){
    TestQueue();
    return 0;
}