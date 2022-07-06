//
// Created by 金冠宇 on 2022/7/6.
//
#include <stdio.h>

#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int front, rear;
    int tag;
} circleSequenceStrack;

void InitQueue(circleSequenceStrack &Q);//初始化
bool QueueEmpty(circleSequenceStrack Q);//判空
bool EnQueue(circleSequenceStrack &Q, int t);//入队操作
bool DeQueue(circleSequenceStrack &Q, int &x);//出队操作
bool GetHead(circleSequenceStrack Q, int &x);//获取队头元素,用x返回

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

/**测试模块**/
//打印整个队列
void PrintQueue(circleSequenceStrack Q){
    printf("开始打印队列\n");
    while(Q.front!=Q.rear){
        printf("Q[%d]=%d\n",Q.front,Q.data[Q.front]);
        Q.front=(Q.front+1)%MaxSize;
    }
    printf("打印完毕！\n");
}

//测试
void TestQueue(){
    printf("开始测试！\n");
    circleSequenceStrack Q;
    InitQueue(Q);
    if (EnQueue(Q, 1)) {
        printf("入队成功啦！\n");
    } else {
        printf("入队失败了\n");
    }
    if (EnQueue(Q, 2)) {
        printf("入队又成功啦！\n");
    } else {
        printf("入队又失败了\n");
    }
    PrintQueue(Q);
    int x;
    if (DeQueue(Q, x)) {
        printf("出队成功，弹出的元素为:%d\n", x);
    } else {
        printf("出队失败了，再检出一下吧！\n");
    }
    if (GetHead(Q, x)) {
        printf("获取队头成功！,队头元素为：%d\n", x);
    } else {
        printf("获取队头元素失败！\n");
    }
    if (DeQueue(Q, x)) {
        printf("出队成功，弹出的元素为:%d\n", x);
    } else {
        printf("出队失败了，再检出一下吧！\n");
    }
    if (QueueEmpty(Q)) {
        printf("队空啦\n");
    } else {
        printf("队非空\n");
    }

    printf("结束测试！\n");
}
/**测试模块**/

int main(){
    TestQueue();
    return 0;
}