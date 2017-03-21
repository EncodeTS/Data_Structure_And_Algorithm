#include <iostream>

using namespace std;

int maxSubSum(int K, int *A)
{
    // 记录当前加和以及历史最大加和
    int thissum = 0, maxsum = 0;
    for (int i = 0; i < K; i++) {
        thissum += *(A + i);
        if (thissum > maxsum) {
            maxsum = thissum;
        }
        if (thissum < 0) {
            thissum = 0;
        }
    }
    return maxsum;
}

int main()
{
    int K;
    cin >> K;  // 记录元素数量
    int *arr = new int[K];
    for (int i = 0; i < K; i++) {
        cin >> *(arr + i);
    }
    int num;  // 记录最大和
    num = maxSubSum(K, arr);
    cout << num << endl;
}
