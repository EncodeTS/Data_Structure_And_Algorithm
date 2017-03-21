#include <iostream>

using namespace std;

int maxSubSum(int K, int A[], int &first, int&last)
{
    // flag用于判断输入元素是否全为负数, keep_first用于记录当前最大和的开始位置
    int thissum = 0, maxsum = 0, flag = 0, keep_first = 0;
    first = 0, last = 0;
    for (int i = 0; i < K; i++)
    {
        thissum += A[i];
        // 只要有一个大于0的元素，就将flag置为1
        if (A[i] >= 0) {
            flag = 1;
        }
        if (thissum > maxsum) {
            // 如果当前加和大于最大加和，则更新初始和最后位置
            first = keep_first;
            last = i;
            maxsum = thissum;
        }
        if (thissum < 0) {
            // 如果当前加和小于0，则将开始位置挪至下一个位置
            keep_first = i + 1;
            thissum = 0;
        }
    }
    first = A[first];
    last = A[last];
    // 如果全为0
    if (maxsum == 0 & flag == 1) {
        first = 0; last = 0;
    }
    // 如果全为负
    if (maxsum == 0 & flag == 0) {
        first = A[0]; last = A[K - 1];
    }
    return maxsum;
}

int main()
{
    int K;
    cin >> K;
    int arr[10000];
    for (int i = 0; i < K; i++) {
        cin >> arr[i];
    }
    int num, first, last;
    num = maxSubSum(K, arr, first, last);

    cout << num << " " << first << " " << last << endl;
}
