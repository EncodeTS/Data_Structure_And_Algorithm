#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read() {
    // 元素数量
    int num;
    scanf("%d", &num);
    // 建立新的头结点
    List front = (List)malloc(sizeof(struct Node));
    front->Next = NULL;
    // 建立指向最后有效节点的指针，遍历时使用
    PtrToNode last = front;

    // 读入元素
    for (int i = 0; i < num; i++) {
        // 新建节点，注意让新节点next指向空
        PtrToNode node = (PtrToNode)malloc(sizeof(struct Node));
        node->Next = NULL;
        scanf("%d", &node->Data);
        last->Next = node;
        last = node;
    }
    // 返回头结点
    return front;
}

void Print(List L) {
    // 指向第一个元素
    PtrToNode last = L->Next;
    // 如果第一个元素为空，直接打印NULL并返回
    if (!last) {
        printf("NULL\n");
        return;
    }
    while (last) {
        printf("%d ", last->Data);
        last = last->Next;
    }
    printf("\n");
}

List Merge(List L1, List L2);

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Merge(List L1, List L2)
{
    PtrToNode p1 = L1->Next, p2 = L2->Next;
    PtrToNode front = (List)malloc(sizeof(struct Node));  // 建立头结点
    PtrToNode plast = front;  // 最后有效节点

    // 当p1和p2都不为空的时候
    while (p1 && p2) {
        if (p1->Data <= p2->Data) {
            // p1更小，最后有效节点指向p1
            plast->Next = p1;
            // 更新plast到p1
            plast = p1;
            // p1指向下一元素
            p1 = p1->Next;
        }
        else {
            plast->Next = p2;
            plast = p2;
            p2 = p2->Next;
        }
    }

    // 如果p1不为空
    if (p1) {
        plast->Next = p1;
    }
    // 反之p2不为空
    else {
        plast->Next = p2;
    }
    L1->Next = NULL;
    L2->Next = NULL;
    return front;
}
