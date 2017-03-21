#include <iostream>
using namespace std;

#define length 10
#define null -1

typedef struct BTree *T;
struct BTree
{
    int num;  // 存储树的节点数目
    char data[length];  // 存储子节点的内容
    int next[length][2]; // 存储子节点的编号，如果为空，则存储为null(-1)
};

T create_tree(int num)
{
    char str;
    char lchild, rchild;
    T tree = new BTree;
    tree->num = num;
    // 依次读入每个节点的内容
    for (int i = 0; i < num; i++) {
        cin >> str >> lchild >> rchild;
        tree->data[i] = str;
        if (lchild != '-') { tree->next[i][0] = lchild - '0'; }
        else { tree->next[i][0] = null; }

        if (rchild != '-') { tree->next[i][1] = rchild - '0'; }
        else { tree->next[i][1] = null; }
    }
    return tree;
}

int find_root(T tree) {
    // 某个节点是子节点，则给对应节点count +1
    int count[length] = { 0 };
    for (int i = 0; i < tree->num; i++) {
        for (int j = 0; j < 2; j++) {
            if (tree->next[i][j] != null) {
                count[tree->next[i][j]] = 1;
            }
        }
    }
    // 遍历数组，找到值为0的那一项即为根节点编号
    for (int i = 0; i < tree->num; i++) {
        if (count[i] == 0) {
            return i;
        }
    }
    // 否则树为空
    return null;
}

int isomorphic(T t1, T t2, int r1, int r2)
{
    // r1,r2存储当前树节点编号
    // 当r1与r2都为空
    if (r1 == null && r2 == null) { return 1; }
    // 当r1与r2一个为空，另一个不为空
    if ((r1 != null && r2 == null) || (r1 == null && r2 != null)) { return 0; }
    // 当r1与r2存储的内容不同的时候
    if (t1->data[r1] != t2->data[r2]) { return 0; }
    // 当r1与r2的左子树都为空的时候，则看右子树是否同构
    if ((t1->next[r1][0] == null) && (t2->next[r2][0] == null)) {
        return isomorphic(t1, t2, t1->next[r1][1], t2->next[r2][1]);
    }
    // 当r1与r2的左子树都不为空，且存储内容相等的时候，则不需要翻转树
    if (((t1->next[r1][0] != null) && (t2->next[r2][0] != null)) &&
        (t1->data[t1->next[r1][0]] == t2->data[t2->next[r2][0]])) {
        return (isomorphic(t1, t2, t1->next[r1][0], t2->next[r2][0]) &&
            isomorphic(t1, t2, t1->next[r1][1], t2->next[r2][1]));
    }
    // 否则翻转r2的左右子树
    else {
        return (isomorphic(t1, t2, t1->next[r1][0], t2->next[r2][1]) &&
            isomorphic(t1, t2, t1->next[r1][1], t2->next[r2][0]));
    }
}

int main()
{
    int num1, num2;
    cin >> num1;
    T t1 = create_tree(num1);
    cin >> num2;
    T t2 = create_tree(num2);
    int r1 = find_root(t1);
    int r2 = find_root(t2);
    if (isomorphic(t1, t2, r1, r2)) { cout << "Yes" << endl; }
    else { cout << "No" << endl; }
    return 0;
}
