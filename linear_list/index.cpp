//
// Created by Guanyu Jin on 2021/12/30.
//
//静态表
#define MaxSize 50
typedef struct {
    int data[MaxSize];
    int length;
} Sqlist;

void InitList(Sqlist &L) {
    for (int i = 0; i < MaxSize; i++) {
        L.data[i] = 0;
    };
    L.length = 0;
}

int main() {
    Sqlist sqlist;
    InitList(sqlist);

    return 0;
};
