//
// Created by Guanyu Jin on 2021/12/30.
//
#include <stdio.h>
//静态表
#define MaxSize 50
typedef struct {
    int data[MaxSize];
    int length;
} SqList;

//函数声明
void InitList(SqList &L);                           //初始化
bool Empty(SqList L);                               //判空
bool ListInsert(SqList &L, int i, int e);           //插入
bool ListDelete(SqList &L, int i, int &e);          //删除
int GetElem(SqList L, int i);                       //按位查找
int LocateElem(SqList L, int e);                    //按值查找
bool LocateChangeElem(SqList &L, int e, int em);    //按值修改
bool getChangeElem(SqList &L, int i, int em);       //按位修改

void InitList(SqList &L) {
    for (int i = 0; i < MaxSize; i++) {
        L.data[i] = 0;
    };
    L.length = 0;
}

bool Empty(SqList L) {
    return L.length == 0;
};

/*
 * 最好情况：新元素插入到表尾，不需要移动元素 i=n+1，循环0次，最好时间复杂度 = O(1)
 * 最坏情况：新元素插入到表头，需要将原有的n个元素全部后移 i=1,循环n次；最坏时间复杂度 = O(n)
 * 平均情况：平均时间复杂度 = O(n)
 */
bool ListInsert(SqList &L, int i, int e) {
    if (i < 1 || i > L.length + 1) {
        return false;
    };
    if (L.length >= MaxSize) {
        return false;
    };
    for (int index = L.length; index >= i; index--) {
        L.data[index] = L.data[index - 1];
    };
    L.data[i - 1] = e;
    L.length++;
    return true;
}

/*
 * 最好情况：新元素插入到表尾，不需要移动元素 i=n+1，循环0次，最好时间复杂度 = O(1)
 * 最坏情况：新元素插入到表头，需要将原有的n个元素全部后移 i=1,循环n次；最坏时间复杂度 = O(n)
 * 平均情况：平均时间复杂度 = O(n)
 */
bool ListDelete(SqList &L, int i, int &e) {
    if (i < 0 || i > L.length) {
        return false;
    };
    e = L.data[i - 1];
    for (int index = i; index < L.length; index++) {
        L.data[index - 1] = L.data[index];
    };
    L.length--;
    return true;
};

int GetElem(SqList L, int i) {
    if (i < 0 || i > L.length) return -1;
    return L.data[i - 1];
}

int LocateElem(SqList L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (e == L.data[i]) {
            return i + 1;
        };
    };
    return -1;
}

bool LocateChangeElem(SqList &L, int e, int em) {
    int bitOrder = LocateElem(L, e);
    if (bitOrder == -1) {
        return false;
    } else {
        L.data[bitOrder - 1] = em;
        return true;
    };
}

bool getChangeElem(SqList &L, int i, int em) {
    if (i < 0 || i > L.length) return false;
    L.data[i] = em;
    return true;
};

int main() {
    // 静态表
    SqList L;
    InitList(L);
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3;
    //插入操作
    if (ListInsert(L, 2, 8)) {
        printf("插入成功了");
    } else {
        printf("插入失败了，i的位置不合法，请检查");
    }
    LocateChangeElem(L, 3, 9);
    return 0;
};
