//
// Created by Guanyu Jin on 2021/12/30.
//
#include <stdlib.h>
//静态表
#define MaxSize 50
typedef struct {
    int data[MaxSize];
    int length;
} SqlistStatic;

void InitListStatic(SqlistStatic &L) {
    for (int i = 0; i < MaxSize; i++) {
        L.data[i] = 0;
    };
    L.length = 0;
}

typedef struct {
    int *data;
    int maxSize;
    int length;
} SqlistDynamic;

void InitListDynamic(SqlistDynamic &dynamicList) {
    dynamicList.data = (int *) malloc(MaxSize * sizeof(int));
    dynamicList.maxSize = MaxSize;
    dynamicList.length = 0;
}

/*
 * 最好情况：新元素插入到表尾，不需要移动元素 i=n+1，循环0次，最好时间复杂度 = O(1)
 * 最坏情况：新元素插入到表头，需要将原有的n个元素全部后移 i=1,循环n次；最坏时间复杂度 = O(n)
 * 平均情况：平均时间复杂度 = O(n)
 */
bool ListInsert(SqlistStatic &L, int i, int e) {
    if (i < 1 || i > L.length + 1) {
        return false;
    };
    if (L.length >= MaxSize) {
        return false;
    };
    for (int index = L.length; index >= i; i--) {
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
bool ListDelete(SqlistStatic &L, int i, int &e) {
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

int main() {
    // 静态表
    SqlistStatic staticList;
    InitListStatic(staticList);
    // 动态表
    SqlistDynamic dynamicList;
    InitListDynamic(dynamicList);
    return 0;
};

//DestroyList
