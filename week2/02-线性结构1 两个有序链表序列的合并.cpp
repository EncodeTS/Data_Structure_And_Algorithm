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
    // Ԫ������
    int num;
    scanf("%d", &num);
    // �����µ�ͷ���
    List front = (List)malloc(sizeof(struct Node));
    front->Next = NULL;
    // ����ָ�������Ч�ڵ��ָ�룬����ʱʹ��
    PtrToNode last = front;

    // ����Ԫ��
    for (int i = 0; i < num; i++) {
        // �½��ڵ㣬ע�����½ڵ�nextָ���
        PtrToNode node = (PtrToNode)malloc(sizeof(struct Node));
        node->Next = NULL;
        scanf("%d", &node->Data);
        last->Next = node;
        last = node;
    }
    // ����ͷ���
    return front;
}

void Print(List L) {
    // ָ���һ��Ԫ��
    PtrToNode last = L->Next;
    // �����һ��Ԫ��Ϊ�գ�ֱ�Ӵ�ӡNULL������
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
    PtrToNode front = (List)malloc(sizeof(struct Node));  // ����ͷ���
    PtrToNode plast = front;  // �����Ч�ڵ�

    // ��p1��p2����Ϊ�յ�ʱ��
    while (p1 && p2) {
        if (p1->Data <= p2->Data) {
            // p1��С�������Ч�ڵ�ָ��p1
            plast->Next = p1;
            // ����plast��p1
            plast = p1;
            // p1ָ����һԪ��
            p1 = p1->Next;
        }
        else {
            plast->Next = p2;
            plast = p2;
            p2 = p2->Next;
        }
    }

    // ���p1��Ϊ��
    if (p1) {
        plast->Next = p1;
    }
    // ��֮p2��Ϊ��
    else {
        plast->Next = p2;
    }
    L1->Next = NULL;
    L2->Next = NULL;
    return front;
}
