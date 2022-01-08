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
