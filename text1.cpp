#include <iostream>
using namespace std;

int countContinuousRanges(int n) {
    int count = 0; // 记录符合条件的连续自然数段的数量

    // 从 k = 2 开始尝试
    for (int k = 2; k * (k - 1) < 2 * n; k++) {
        // 计算 n - k*(k-1)/2
        int sumK = k * (k - 1) / 2;
        if (n > sumK && (n - sumK) % k == 0) {
            count++; // 如果 a 为正整数，增加计数
        }
    }

    return count;
}

int main() {
    int n;
    cout << "Enter a positive integer n: ";
    cin >> n;

    int result = countContinuousRanges(n);
    cout << "The number of different continuous ranges that sum to " << n << " is: " << result << endl;

    return 0;
}
