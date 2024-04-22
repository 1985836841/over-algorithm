/**
* 顺序表
* 
*/
#include<stdio.h>

typedef int ElemType;
#define STATIC_MAX_SIZE 10

// 静态分配
typedef struct {
    ElemType data[STATIC_MAX_SIZE];  // 静态分配, 容量为 10
    int length;  // 代表当前的顺序表用了多大
} SqListStatic;


// 初始化静态分配的顺序表
void InitSqList(SqListStatic *s){
    for(int i = 0; i < STATIC_MAX_SIZE; i++){
        s->data[i] = 0;
    }
    s->length = 0;
}

// 插入一个元素
int InsertElem(SqListStatic *s, int index, ElemType e){
    // 如果已经到最大了, 则返回 false
    if(s->length >= STATIC_MAX_SIZE){
        return 1;
    }

    // 如果位置不合法, 则返回 false
    if (index < 0 || index >= STATIC_MAX_SIZE){
       return 1;
    }

    // 将后边的元素往后移动
    for(int i = s->length - 1; i >= index; i--){
        s->data[i + 1] = s->data[i];
    }
    s->data[index] = e;
    s->length++;
    return 0;
}

// 测试
int main(){
    SqListStatic s;
    InitSqList(&s);
    if(InsertElem(&s, 0, 100) != 0){
        printf("出错啦出错来, insert 出错啦");
    }
    for(int i = 0; i < s.length; i++){
        printf("%d\n", s.data[i]);
    }
}