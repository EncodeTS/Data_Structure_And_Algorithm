#include <iostream>
using namespace std;

#define length 10

typedef struct Btree *T;
struct Btree {
    int num;
    char data[length][2];
};

typedef struct Queue *Q;
struct Queue {
    int front = 0;
    int rear = 0;
    int data[length];
};

bool isEmpty(Q queue) {
    if (queue->front == queue->rear) {
        return true;
    }
    return false;
}

int enQueue(Q queue, int x) {
    if ((queue->rear + 1) % length == queue->front) {
        cout << "队列已满" << endl;
        return -1;
    }
    queue->data[++queue->rear % length] = x;
    return 0;
}

int deQueue(Q queue, int &x) {
    if (queue->front == queue->rear) {
        cout << "队列已空" << endl;
        return -1;
    }
    x = queue->data[++queue->front % length];
    return 0;
}

T create_tree() {
    int num;
    char lchild, rchild;
    cin >> num;

    T tree = new Btree;
    tree->num = num;

    for (int i = 0; i < tree->num; i++) {
        cin >> lchild >> rchild;
        tree->data[i][0] = lchild;
        tree->data[i][1] = rchild;
    }
    return tree;
}

int find_root(T tree) {
    // 某个节点是子节点，则给对应节点count+1
    int count[10] = { 0 };
    for (int i = 0; i < tree->num; i++) {
        for (int j = 0; j < 2; j++) {
            if (tree->data[i][j] != '-') {
                count[tree->data[i][j] - '0'] = 1;
            }
        }
    }
    // 遍历数组，找到值为0的那一项即为根节点编号
    for (int i = 0; i < tree->num; i++) {
        if (count[i] == 0) {
            return i;
        }
    }
}

void list_leaves(T tree, Q result) {
    // 找到根节点编号
    int root_index = find_root(tree);
    // 创建一个队列，用于层序遍历树
    Q qu = new Queue;
    enQueue(qu, root_index);
    int x; //存储每次遍历的编号值
    for (int i = 0; i < tree->num; i++) {
        // 队列不为空，则出队最前面的元素
        if (!isEmpty(qu)) {
            deQueue(qu, x);
        }
        // 并入队该元素的子节点编号
        for (int j = 0; j < 2; j++) {
            if (tree->data[x][j] != '-') {
                enQueue(qu, tree->data[x][j] - '0');
            }
        }
        // 如果某个节点的两个子节点都为空，则记录至result队列中
        if (tree->data[x][0] == '-' && tree->data[x][1] == '-') {
            enQueue(result, x);
        }
    }
}

int main()
{
    T tree = create_tree();
    Q result = new Queue;
    list_leaves(tree, result);
    int x;
    deQueue(result, x);
    cout << x;
    while (!isEmpty(result)) {
        deQueue(result, x);
        cout << " " << x;
    }
    return 0;
}
