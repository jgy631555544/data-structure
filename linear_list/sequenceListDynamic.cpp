//
// Created by SESA622684 on 2022/2/10.
//

#include <stdlib.h>

#define InitSize 10
typedef struct {
    int *data;
    int maxSize;
    int length;
} SeqList;

//函数声明
bool InitList(SeqList &L);                  //初始化
bool Empty(SeqList L);                      //判空
bool Full(SeqList L);                       //判满
void IncreaseSize(SeqList &L, int len);     //动态扩展空间
bool ListInsert(SeqList &L, int i, int e);    //插入
int GetElem(SeqList L, int i);               //按位查找
int LocateElem(SeqList L, int e);            //按值查找
bool ListDelete(SeqList &L, int i, int &e); //删除
void DestroySqList(SeqList &L);             //销毁

bool InitList(SeqList &L) {
    L.data = (int *) malloc(InitSize * sizeof(int));
    if (L.data == NULL) {
        return false;
    }
    L.length = 0;
    L.maxSize = InitSize;
    return true;
}

bool Empty(SeqList L) {
    return L.length == 0;
}

bool Full(SeqList L) {
    return L.length >= L.maxSize;
}

void IncreaseSize(SeqList &L, int len) {
    int *point = L.data;
    L.data = (int *) malloc((InitSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++) {
        L.data[i] = point[i];
    };
    L.maxSize = L.maxSize + len;
    free(point);
}

bool ListInsert(SeqList &L, int i, int e) {
    if (i < 1 || i > L.length + 1) return false;
    if (Full(L)) return false;
    for (int index = L.length; index > i; index--) {
        L.data[index] = L.data[index - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

int GetElem(SeqList L, int i) {
    if (i < 0 || i > L.length) return -1;
    return L.data[i - 1];
}

int LocateElem(SeqList L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (e == L.data[i])return i + 1;
    };
    return -1;
};

void DestroySqList(SeqList &L) {
    free(L.data);
    L.data = NULL;
    L.length = 0;
}

bool ListDelete(SeqList &L, int i, int &e) {
    if (i < 0 || i > L.length) {
        return false;
    };
    e = L.data[i];
    for (int index = i; i < L.length; index++) {
        L.data[index - 1] = L.data[index];
    };
    L.length--;
    return true;
};

int main() {
    SeqList L;
    InitList(L);
    return 0;
}