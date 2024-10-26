#include <iostream>
#include <vector>

int extendedEuclid(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; 
        y = 0; 
        return a;
    }
    int gcd = extendedEuclid(b, a % b, y, x);
    y -= (a / b) * x;
    return gcd;
}

int chineseRemainder(const std::vector<int> &a, const std::vector<int> &m) {
    int M = 1;
    for (int mi : m) M *= mi;

    int result = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        int ai = a[i], mi = m[i];
        int Mi = M / mi;
        int x, y;
        extendedEuclid(Mi, mi, x, y);
        result += ai * x * Mi;
    }
    return result % M;
}

int main() {
    int a, b, c, d, e, f, g, h, i, j;
    
    // 输入最后剩下的士兵人数
    std::cout << "Enter remainders for 10 to 2 columns (a to j): ";
    std::cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;

    std::vector<int> remainders = {a, b, c, d, e, f, g, h, i, j};
    std::vector<int> moduli = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    int result = chineseRemainder(remainders, moduli);
    std::cout << "The minimum number of soldiers is: " << result << std::endl;

    return 0;
}
